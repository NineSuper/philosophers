/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:19:07 by tde-los-          #+#    #+#             */
/*   Updated: 2023/09/18 10:16:12 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
! 	HEADER
* ----------------------------
? 🌐 Philosophers by tde-los-

* number_of_philosophers x 🐁
* time_to_die x_ms ⚰️
* time_to_eat x_ms🥞
* time_to_sleep x_ms 💤
* max_eat x meal 🍴 [optionnel]
* ---------------------------
*/

#include "philo.h"

void	ft_header(t_data *s_data)
{
	printf("%s", HEADER_SPACE);
	printf("%s\n", HEADER_NAME);
	printf("%s %d 🐁\n", HEADER_NB_PH, s_data->number_of_philosophers);
	printf("%s %dms ⚰️\n", HEADER_TIME_DIE, s_data->time_to_die);
	printf("%s %dms 🥞\n", HEADER_TIME_EAT, s_data->time_to_eat);
	printf("%s %dms 💤\n", HEADER_TIME_SLEEP, s_data->time_to_sleep);
	if (s_data->max_eat)
		printf("%s %d meal🍴\n", HEADER_MUST_EAT, s_data->max_eat);
	printf("\n%s\n", HEADER_SPACE);
}

long int	time_diff(struct timeval *end)
{
	return ((end->tv_sec * 1000) + (end->tv_usec / 1000));
}

void	ft_message(t_philo *s_philo, int num, int action)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	pthread_mutex_lock(&s_philo->data->isprint);
	s_philo->end = time_diff(&end) - time_diff(&s_philo->start);
	if (action == 1)
		printf("\e[1;32m%ldms %d %s", s_philo->end, num, MSG_FORK);
	else if (action == 2)
	{
		if (s_philo->data->max_eat)
		{
			s_philo->eat++;
			printf("\e[1;33m%ldms %d %s [%d/%d]\n", s_philo->end, num, \
			MSG_EAT, s_philo->eat, s_philo->data->max_eat);
		}
		else
			printf("\e[1;33m%ldms %d %s\n", s_philo->end, num, MSG_EAT);
	}
	else if (action == 3)
		printf("\e[1;35m%ldms %d %s", s_philo->end, num, MSG_SLEEP);
	else if (action == 4)
		printf("\e[1;36m%ldms %d %s", s_philo->end, num, MSG_THINING);
	else if (action == 5)
		printf("\e[1;31m%ldms %d %s", s_philo->end, num, MSG_DIE);
	pthread_mutex_unlock(&s_philo->data->isprint);
}
