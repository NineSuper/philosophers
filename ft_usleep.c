/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:59:06 by tde-los-          #+#    #+#             */
/*   Updated: 2023/09/18 14:02:58 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
philo->fork = 0; rien mutex
philo->fork = 1; r_f mutex
philo->fork = 2; l_f mutex
philo->fork = 3; r_f et l_f mutex
*/

void	ft_free_fork(t_philo *philo)
{
	if (!philo->fork)
		return ;
	else if (philo->fork == 1)
		pthread_mutex_unlock(philo->r_f);
	else if (philo->fork == 2)
		pthread_mutex_unlock(&philo->l_f);
	else if (philo->fork == 3)
	{
		pthread_mutex_unlock(philo->r_f);
		pthread_mutex_unlock(&philo->l_f);
	}
	philo->fork = 0;
}

long int	actual_time(void)
{
	long int			time;
	struct timeval		current_time;

	time = 0;
	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

void	ft_usleep(int time_in_ms, t_philo *s_philo)
{
	long int	start_time;

	start_time = 0;
	start_time = actual_time();
	while ((actual_time() - start_time) < time_in_ms && !check_death(s_philo))
		usleep(1);
}
