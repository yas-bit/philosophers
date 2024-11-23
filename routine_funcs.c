/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yraiss <yraiss@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:05:31 by yraiss            #+#    #+#             */
/*   Updated: 2023/06/23 23:19:24 by yraiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo(t_philo *philo, char *msg, long long time)
{
	pthread_mutex_lock(&philo->common->die);
	printf("%lld %d %s\n", time, philo->id, msg);
	pthread_mutex_unlock(&philo->common->die);
}

void	think(t_philo *philo)
{
	if (philo->id % 2 != 0)
	{
		print_philo(philo, "is thinking", time_counter()
			- philo->common->start);
		usleep(20);
	}
}

void	ph_sleep(t_philo *philo)
{
	print_philo(philo, "is sleeping", time_counter() - philo->common->start);
	ft_usleep(philo->common->time_to_sleep);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_philo(philo, "has taken a fork", time_counter()
		- philo->common->start);
	pthread_mutex_lock(philo->right_fork);
	print_philo(philo, "has taken a fork", time_counter()
		- philo->common->start);
	print_philo(philo, "is eating", time_counter() - philo->common->start);
	pthread_mutex_lock(&philo->common->die);
	philo->last_meal = time_counter();
	if (philo->common->on == 1)
		philo->must_eat++;
	pthread_mutex_unlock(&philo->common->die);
	ft_usleep(philo->common->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
