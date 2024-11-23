/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yraiss <yraiss@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:21:20 by yraiss            #+#    #+#             */
/*   Updated: 2023/06/24 01:56:42 by yraiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	think(philo);
	while (1)
	{
		eat(philo);
		ph_sleep(philo);
		print_philo(philo, "is thinking", time_counter()
			- philo->common->start);
	}
	return (NULL);
}

int	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->common->die);
	if (time_counter() - philo->last_meal >= philo->common->time_to_die)
	{
		printf("%lld %d died\n", time_counter()
			- philo->common->start, philo->id);
		return (1);
	}
	pthread_mutex_unlock(&philo->common->die);
	return (0);
}

int	check_must_eat(t_philo *philo)
{
	int	on;

	on = 0;
	pthread_mutex_lock(&philo->common->die);
	if (philo->must_eat > philo->common->num_must_eat)
		on = 1;
	if (philo->must_eat < philo->common->num_must_eat)
		on = 0;
	pthread_mutex_unlock(&philo->common->die);
	return (on);
}

int	death(t_philo *philo)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < philo->common->num_philo)
		{
			if (check_death(&philo[i]) || check_must_eat(&philo[i]))
				return (1);
		}
		usleep(200);
	}
	return (0);
}

int	create_philos(t_philo *philo)
{
	int	i;

	i = 0;
	philo->common->start = time_counter();
	while (i < philo->common->num_philo)
	{
		philo[i].last_meal = time_counter();
		if (pthread_create(&philo[i].ph, NULL, &routine, &philo[i]) != 0)
			return (0);
		usleep(200);
		i++;
	}
	if (death(philo))
		return (0);
	return (1);
}
