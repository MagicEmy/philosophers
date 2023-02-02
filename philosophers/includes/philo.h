/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:41:32 by emanuela          #+#    #+#             */
/*   Updated: 2023/02/02 16:24:39 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "ph_defines.h"
# include "colors.h"

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_data
{
	int				num_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_sleep;
	int				num_meals;
	int				meals;
	int				alive;
	long			time_start;
	pthread_mutex_t	mutex_life;
	pthread_mutex_t	mutex_meals;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	*mutex;
	struct s_philo	*philo;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			ph_last_meal;
	long			ph_sleep;
	long			ph_die;
	pthread_t		ph;
	t_data			*data;
}	t_philo;

void		error(char *msg);

//valid input and data init
int			check_args(int argc, char **argv);
t_data		*data_init(int argc, char **argv);

//time
long		ph_get_time(void);
void		ph_usleep(long ms);

//routine
void		*ph_routine(void *philo_stru);

void		*ph_life(void *data_struct);
int			check_life(t_data *data);
int			print_msg(t_philo *philo, int case_pr);

//threads and mutex
int			ph_create_philo(t_data *data);
int			ph_join_philo(t_data *data);
int			ph_mutex_init(t_data *data);
int			ph_mutex_destroy(t_data *data);

int			mutex_lock_fork(t_philo *philo);
void		mutex_unlock_fork(t_philo *philo);

#endif
