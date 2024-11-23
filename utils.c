/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yraiss <yraiss@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:01:05 by yraiss            #+#    #+#             */
/*   Updated: 2023/06/24 01:01:05 by yraiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if (str[i] >= 'a' && str[i] <= 'z')
		return (-1);
	if (str[i] >= 'A' && str[i] <= 'Z')
		return (-1);
	return (res);
}

long long	time_counter(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	ft_usleep(long int time)
{
	long int	start_time;

	start_time = time_counter();
	while ((time_counter() - start_time) != time)
		usleep(50);
}

void	my_free(t_philo *philo, t_common *com)
{
	int	i;

	i = 0;
	while (i < com->num_philo)
		pthread_mutex_destroy(&com->forks[i++]);
	pthread_mutex_destroy(&com->die);
	free(philo);
	free(com->forks);
	free(com);
}
