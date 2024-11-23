/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yraiss <yraiss@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:53:45 by yraiss            #+#    #+#             */
/*   Updated: 2023/06/23 22:46:10 by yraiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_params(int argc, char **argv, t_common *com)
{
	com->on = 0;
	if (argc == 6)
	{
		com->num_must_eat = ft_atoi(argv[5]);
		com->on = 1;
	}
	else
		com->num_must_eat = 0;
	com->num_philo = ft_atoi(argv[1]);
	com->time_to_die = ft_atoi(argv[2]);
	com->time_to_eat = ft_atoi(argv[3]);
	com->time_to_sleep = ft_atoi(argv[4]);
	com->stop = 0;
}

int	init_mutex(t_common *common)
{
	int	i;

	i = 0;
	common->forks = malloc(common->num_philo * sizeof(pthread_mutex_t));
	if (!common->forks)
		return (0);
	while (i < common->num_philo)
	{
		if (pthread_mutex_init(&common->forks[i], NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_init(&common->die, NULL) != 0)
		return (0);
	return (1);
}

void	init_philos(t_philo *philo, t_common *common)
{
	int	ph_num;
	int	i;

	i = 0;
	ph_num = common->num_philo;
	while (i < ph_num)
	{
		philo[i].id = i + 1;
		philo[i].common = common;
		philo[i].left_fork = &common->forks[i];
		philo[i].right_fork = &common->forks[(i + 1) % ph_num];
		philo[i].must_eat = 0;
		i++;
	}
}
