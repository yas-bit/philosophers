/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yraiss <yraiss@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:13:44 by yraiss            #+#    #+#             */
/*   Updated: 2023/06/24 01:50:31 by yraiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	args_check(int argc, char **argv)
{
	int	i;
	int	ag;

	i = 1;
	if (argc != 6 && argc != 5)
		return (0);
	while (argv[i])
	{
		ag = ft_atoi(argv[i]);
		if (ag < 1)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_philo		*philo;
	t_common	*common_in;

	common_in = malloc(sizeof(t_common));
	if (!common_in)
		return (1);
	if (!args_check(argc, argv))
	{
		printf("Error\n");
		free(common_in);
		return (1);
	}
	init_params(argc, argv, common_in);
	philo = malloc(common_in->num_philo * sizeof(t_philo));
	if (philo == NULL)
		return (1);
	if (!init_mutex(common_in))
		return (1);
	init_philos(philo, common_in);
	if (!create_philos(philo))
		return (1);
	my_free(philo, common_in);
	return (0);
}
