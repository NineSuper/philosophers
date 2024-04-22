/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:15:54 by tde-los-          #+#    #+#             */
/*   Updated: 2023/09/18 14:44:09 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_one_philo(t_data *s_data)
{
	printf("\e[1;32m%dms %d %s", 0, 1, MSG_FORK);
	usleep(s_data->time_to_die * 1000);
	printf("\e[1;31m%dms %d %s", s_data->time_to_die, 1, MSG_DIE);
	free(s_data);
	exit (0);
}

void	ft_arg_philo(t_data *s_data)
{
	int	i;

	i = -1;
	pthread_mutex_init(&s_data->fork, NULL);
	while (++i < s_data->number_of_philosophers)
		pthread_mutex_init(&s_data->s_philo[i].l_f, NULL);
	i = -1;
	gettimeofday(&s_data->start, NULL);
	while (++i < s_data->number_of_philosophers)
		ft_init_philo(s_data, &s_data->s_philo[i], i);
	i = -1;
	while (++i < s_data->number_of_philosophers)
		pthread_create(&s_data->s_philo[i].id, NULL, init_thread,
			&s_data->s_philo[i]);
}

void	ft_init_philo(t_data *s_data, t_philo *s_philo, int nb)
{
	s_philo->data = s_data;
	s_philo->num = nb + 1;
	s_philo->start = s_data->start;
	s_philo->eat = 0;
	s_philo->time_to_die = s_data->time_to_die;
	s_philo->time_to_eat = s_data->time_to_eat;
	s_philo->time_to_sleep = s_data->time_to_sleep;
	s_philo->end = 0;
	if (nb == s_data->number_of_philosophers - 1)
		s_philo->r_f = &s_data->s_philo[0].l_f;
	else
		s_philo->r_f = &s_data->s_philo[nb + 1].l_f;
}
