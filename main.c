/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:05:15 by tde-los-          #+#    #+#             */
/*   Updated: 2023/09/18 14:42:41 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_add_arg(int argc, char **argv, t_data *s_data)
{
	s_data->number_of_philosophers = ft_atoi(argv[1]);
	if (s_data->number_of_philosophers < 1)
		ft_error_msg(ERROR_PHILO, s_data);
	s_data->time_to_die = ft_atoi(argv[2]);
	s_data->time_to_eat = ft_atoi(argv[3]);
	s_data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		s_data->max_eat = ft_atoi(argv[5]);
	if (s_data->time_to_die < 60 || s_data->time_to_eat < 60 \
		|| s_data->time_to_sleep < 60)
		ft_error_msg(ERROR_TIME, s_data);
	s_data->f_eat = 0;
}

void	ft_check_arg(int argc, char **argv, t_data *s_data)
{
	char	*args;
	int		i;
	int		j;

	i = 0;
	if (argc < 5 || argc > 6)
		ft_error_msg(ERROR_ARC, s_data);
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
			if (ft_isdigit(argv[i][j]) == 0)
				ft_error_msg(ERROR_DIGIT, s_data);
	}
	ft_add_arg(argc, argv, s_data);
	ft_header(s_data);
	pthread_mutex_init(&s_data->isprint, NULL);
}

int	ft_max_eat(t_data *s_data)
{
	pthread_mutex_lock(&s_data->fork);
	if (s_data->max_eat)
	{
		if (s_data->f_eat == s_data->number_of_philosophers)
		{
			pthread_mutex_unlock(&s_data->fork);
			return (1);
		}
	}
	pthread_mutex_unlock(&s_data->fork);
}

int	main(int argc, char **argv)
{
	t_data	*s_data;
	int		i;

	s_data = ft_calloc(1, sizeof(t_data));
	ft_check_arg(argc, argv, s_data);
	if (s_data->number_of_philosophers == 1)
		return (ft_one_philo(s_data));
	i = s_data->number_of_philosophers;
	s_data->s_philo = ft_calloc(i, sizeof(t_philo));
	ft_arg_philo(s_data);
	while (1)
	{
		pthread_mutex_lock(&s_data->isdie);
		if (s_data->die)
		{
			pthread_mutex_unlock(&s_data->isdie);
			break ;
		}
		pthread_mutex_unlock(&s_data->isdie);
		if (ft_max_eat(s_data))
			break ;
	}
	ft_free_philo(s_data->s_philo, s_data);
}
