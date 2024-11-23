/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yraiss <yraiss@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:13:57 by yraiss            #+#    #+#             */
/*   Updated: 2023/06/23 22:44:07 by yraiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <strings.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_common
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	int				on;
	int				stop;
	long long		start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	die;
}					t_common;

typedef struct s_philo
{
	int				id;
	pthread_t		ph;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long long		last_meal;
	long long		start;
	int				must_eat;
	t_common		*common;
}					t_philo;

//utils
int					ft_atoi(const char *str);
long long			time_counter(void);
void				ft_usleep(long int time);
void				my_free(t_philo *philo, t_common *com);
//initialize
void				init_params(int argc, char **argv, t_common *com);
int					init_mutex(t_common *common);
void				init_philos(t_philo *philo, t_common *common);
//create
int					create_philos(t_philo *philo);
void				create_forks(t_philo *philo, t_common *common);
//death
void				death_check(t_philo *philo);
//routine funcs
void				print_philo(t_philo *philo, char *msg, long long time);
int					die(t_philo *philo);
void				think(t_philo *philo);
void				ph_sleep(t_philo *philo);
void				eat(t_philo *philo);
#endif
