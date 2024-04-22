/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:47:34 by tde-los-          #+#    #+#             */
/*   Updated: 2023/09/18 10:53:47 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_unlock(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_f);
	pthread_mutex_lock(philo->r_f);
	pthread_mutex_unlock(&philo->l_f);
	pthread_mutex_unlock(philo->r_f);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = (char *)s;
	while (i < n)
	{
		temp[i] = 0;
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	reste;
	int	signe;

	i = 0;
	reste = 0;
	signe = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		reste = reste * 10 + str[i] - '0';
		i++;
	}
	return (reste * signe);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > 65535 / size)
		return (NULL);
	str = malloc(nmemb * size);
	if (str)
		ft_bzero(str, nmemb * size);
	return (str);
}
