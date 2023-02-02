/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:08:59 by emlicame          #+#    #+#             */
/*   Updated: 2023/02/02 15:51:12 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_mutex_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_mutex_init(&data->mutex[i], NULL) != 0)
			return (error(ERROR_MUTEX), 1);
		i++;
	}
	if (pthread_mutex_init(&data->mutex_life, NULL) != 0)
		return (error(ERROR_MUTEX), 1);
	if (pthread_mutex_init(&data->mutex_print, NULL) != 0)
		return (error(ERROR_MUTEX), 1);
	if (pthread_mutex_init(&data->mutex_meals, NULL) != 0)
		return (error(ERROR_MUTEX), 1);
	if (pthread_mutex_init(&data->mutex_doc, NULL) != 0)
		return (error(ERROR_MUTEX), 1);
	return (0);
}

int	ph_mutex_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_mutex_destroy(&data->mutex[i]) != 0)
			return (error(ERROR_DESTROY), 1);
		i++;
	}
	if (pthread_mutex_destroy(&data->mutex_life) != 0)
		return (error(ERROR_DESTROY), 1);
	if (pthread_mutex_destroy(&data->mutex_print) != 0)
		return (error(ERROR_DESTROY), 1);
	if (pthread_mutex_destroy(&data->mutex_meals) != 0)
		return (error(ERROR_DESTROY), 1);
	if (pthread_mutex_destroy(&data->mutex_doc) != 0)
		return (error(ERROR_DESTROY), 1);
	return (0);
}

void	philo_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		data->philo[i].data = data;
		data->philo[i].ph_last_meal = ph_get_time();
		data->philo[i].ph_sleep = 0;
		data->philo[i].ph_die = data->time_to_die;
		data->philo[i].meals_eaten = 0;
		i++;
	}
}

int	ph_create_philo(t_data *data)
{
	int			i;
	pthread_t	doctor;

	i = 0;
	philo_init(data);
	data->time_start = ph_get_time();
	while (i < data->num_philo)
	{
		data->philo[i].id = i + 1;
		if (pthread_create(&data->philo[i].ph, NULL, ph_routine, \
		&data->philo[i]) != 0)
			return (error(ERROR_THREAD), 1);
		i++;
	}
	if (pthread_create(&doctor, NULL, ph_life, data) != 0)
		return (0);
	if (pthread_join(doctor, NULL) != 0)
		return (error("Error waiting for threads"), 1);
	return (0);
}

int	ph_join_philo(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_join(data->philo[i].ph, NULL) != 0)
			return (error("Error waiting for threads"), 1);
		i++;
	}
	// if (pthread_join(data->doctor, NULL) != 0)
	// 	return (error("Error waiting for threads"), 1);
	return (0);
}
