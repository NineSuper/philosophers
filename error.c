/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:20:30 by tde-los-          #+#    #+#             */
/*   Updated: 2023/09/18 10:49:26 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_philo(t_philo *s_philo, t_data *s_data)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&s_data->isdie);
	pthread_mutex_unlock(&s_data->isdie);
	pthread_mutex_lock(&s_data->isprint);
	pthread_mutex_unlock(&s_data->isprint);
	pthread_mutex_lock(&s_data->fork);
	pthread_mutex_unlock(&s_data->fork);
	while (++i < s_data->number_of_philosophers)
		pthread_join(s_data->s_philo[i].id, NULL);
	pthread_mutex_destroy(&s_data->isdie);
	pthread_mutex_destroy(&s_data->isprint);
	pthread_mutex_destroy(&s_data->fork);
	free(s_philo);
	free(s_data);
}

void	ft_error_msg(char *message, t_data *s_data)
{
	printf("%s\n", message);
	if (s_data)
		free(s_data);
	exit (0);
}
