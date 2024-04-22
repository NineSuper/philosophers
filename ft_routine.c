/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:51:23 by tde-los-          #+#    #+#             */
/*   Updated: 2023/10/07 10:28:07 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo)
{
	struct timeval	end;

	pthread_mutex_lock(&philo->data->isdie);
	if (philo->data->max_eat)
		if (philo->eat == philo->data->max_eat)
			return (pthread_mutex_unlock(&philo->data->isdie), 1);
	if (philo->data->die)
		return (pthread_mutex_unlock(&philo->data->isdie), 1);
	gettimeofday(&end, NULL);
	philo->time = time_diff(&end) - time_diff(&philo->start);
	if (philo->time - philo->last_eat - 1 > philo->time_to_die)
	{
		ft_message(philo, philo->num, 5);
		philo->data->die = 1;
		return (pthread_mutex_unlock(&philo->data->isdie), 1);
	}
	pthread_mutex_unlock(&philo->data->isdie);
	return (0);
}

void	ft_eat(t_philo *philo)
{
	if (check_death(philo))
	{
		ft_free_fork(philo);
		return ;
	}
	if (philo->data->max_eat)
	{
		if (philo->eat == philo->data->max_eat)
		{
			ft_free_fork(philo);
			return ;
		}
	}
	ft_message(philo, philo->num, 2);
	philo->last_eat = philo->end - 1;
	ft_usleep(philo->time_to_eat, philo);
	ft_free_fork(philo);
}

void	ft_sleep(t_philo *philo)
{
	if (check_death(philo))
		return ;
	ft_message(philo, philo->num, 3);
	ft_usleep(philo->time_to_sleep, philo);
}

void	ft_fork(t_philo *philo)
{
	if (check_death(philo))
		return ;
	if (philo->data->max_eat)
		if (philo->eat == philo->data->max_eat)
			return ;
	ft_message(philo, philo->num, 1);
	pthread_mutex_lock(philo->r_f);
	philo->fork = 1;
	pthread_mutex_lock(&philo->l_f);
	philo->fork = 3;
	if (check_death(philo))
	{
		ft_free_fork(philo);
		return ;
	}
}

/*
? Les philosophes font -> manger -> dormir -> penser
* Pour manger il faut 2 fourchettes une a sa droite une a sa gauche
*/

void	*init_thread(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	philo->id = pthread_self();
	if (philo->num % 2 == 0)
		ft_usleep(philo->time_to_eat, philo);
	while (1)
	{
		if (check_death(philo))
			break ;
		ft_fork(philo);
		ft_eat(philo);
		// if (philo->data->max_eat)
		// 	if (philo->eat == philo->data->max_eat)
		// 		break ;
		ft_sleep(philo);
		if (check_death(philo))
			break ;
		ft_message(philo, philo->num, 4);
	}
	pthread_mutex_lock(&philo->data->fork);
	philo->data->f_eat++;
	pthread_mutex_unlock(&philo->data->fork);
	return (NULL);
}
