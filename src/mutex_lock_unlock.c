/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_lock_unlock.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:15:31 by emlicame          #+#    #+#             */
/*   Updated: 2023/02/06 15:21:57 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_mutex_lock_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex[philo->id - 1]);
	ph_print_msg(philo, 1);
	pthread_mutex_lock(&philo->data->mutex[(philo->id) % \
	philo->data->num_philo]);
	ph_print_msg(philo, 1);
	return (0);
}

void	ph_mutex_unlock_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->mutex[philo->id - 1]);
	pthread_mutex_unlock(&philo->data->mutex[(philo->id) % \
	philo->data->num_philo]);
}

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
	if (pthread_mutex_init(&data->mutex_meals, NULL) != 0)
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
	if (pthread_mutex_destroy(&data->mutex_meals) != 0)
		return (error(ERROR_DESTROY), 1);
	return (0);
}
