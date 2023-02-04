/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:50:08 by emlicame          #+#    #+#             */
/*   Updated: 2023/02/04 19:01:28 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eating(t_philo *philo)
{
	ph_mutex_lock_fork(philo);
	ph_print_msg(philo, 2);
	pthread_mutex_lock(&philo->data->mutex_meals);
	philo->ph_last_meal = ph_get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->mutex_meals);
	ph_usleep(philo->data->time_to_eat);
	ph_mutex_unlock_fork(philo);
	return (0);
}

int	philo_sleeping(t_philo *philo)
{
	if (!check_life(philo->data))
		return (1);
	ph_print_msg(philo, 3);
	ph_usleep(philo->data->time_sleep);
	return (0);
}

int	philo_thinking(t_philo *philo)
{
	if (!check_life(philo->data))
		return (1);
	ph_print_msg(philo, 4);
	usleep(500);
	return (0);
}

void	*ph_routine(void *philo_stru)
{
	t_philo	*philo;

	philo = philo_stru;
	if (philo->data->num_philo == 1)
	{
		ph_print_msg(philo, 1);
		ph_usleep(philo->ph_die);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(500);
	while (check_life(philo->data))
	{
		philo_eating(philo);
		philo_sleeping(philo);
		philo_thinking(philo);
	}
	return (NULL);
}
