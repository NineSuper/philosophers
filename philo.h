/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:59:28 by tde-los-          #+#    #+#             */
/*   Updated: 2023/09/18 14:45:55 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
/*		MESSAGE  ERROR		*/
# define ERROR_ARC "\e[1;42m./philo -nb_of_philosophers\
 -time_to_..-die.&.-eat.&.-sleep -[max_eat]\e[0;00m"
# define ERROR_DIGIT "\e[1;41mMerci de mettre des chiffres\
 pour chaque arguments !\e[0;00m"
# define ERROR_PHILO "\e[1;42mIl n'y a pas assez de philosophe !\e[0;00m"
# define ERROR_TIME "\e[1;42mLe temps doit etre >= 60ms\e[0;00m"
/*			MESSAGE			*/
# define MSG_FORK "has taken a fork🍴\e[0;00m\n"
# define MSG_EAT "is eating🥞\e[0;00m"
# define MSG_SLEEP "is sleeping💤\e[0;00m\n"
# define MSG_THINING "is thinking💡\e[0;00m\n"
# define MSG_DIE "died⚰️\e[0;00m\n"
/*			HEADER			*/
# define HEADER_NAME "\e[1;42m 🌐 Philosophers by tde-los-  \e[0;00m\n"
# define HEADER_NB_PH "\e[1;37mPhilosophers:"
# define HEADER_TIME_DIE "\e[1;37m🕑 time_to_die"
# define HEADER_TIME_EAT "\e[1;37m🕓 time_to_eat"
# define HEADER_TIME_SLEEP "\e[1;37m🕖 time_to_sleep"
# define HEADER_MUST_EAT "\e[1;37m🕜 max_eat"
# define HEADER_SPACE "\e[1;42m                              \e[0;00m\n"

typedef struct s_philo
{
	pthread_t		pid;
	pthread_t		id;
	pthread_mutex_t	isprint;
	pthread_mutex_t	l_f;
	pthread_mutex_t	*r_f;
	struct s_data	*data;
	struct timeval	start;
	long int		end;
	long int		last_eat;
	long int		time;
	int				fork;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num;
	int				eat;
}	t_philo;

typedef struct s_data
{
	pthread_mutex_t	isdie;
	pthread_mutex_t	fork;
	pthread_mutex_t	isprint;
	struct timeval	start;
	t_philo			*s_philo;
	long int		time;
	int				f_eat;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_eat;
	int				die;
}	t_data;

long int	actual_time(void);
long int	time_diff(struct timeval *end);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			check_death(t_philo *philo);
int			ft_one_philo(t_data *s_data);
void		ft_header(t_data *s_data);
void		ft_init_philo(t_data *s_data, t_philo *s_philo, int nb);
void		ft_free_philo(t_philo *s_philo, t_data *s_data);
void		ft_bzero(void *s, size_t n);
void		ft_error_msg(char *message, t_data *s_data);
void		ft_message(t_philo *s_philo, int num, int action);
void		*ft_calloc(size_t nmemb, size_t size);
void		*init_thread(void *data);
void		ft_arg_philo(t_data *s_data);
void		ft_usleep(int time_in_ms, t_philo *s_philo);
void		ft_free_fork(t_philo *philo);
void		ft_unlock(t_philo *philo);

#endif
