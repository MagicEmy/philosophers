/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:38:49 by emlicame          #+#    #+#             */
/*   Updated: 2023/02/02 16:30:38 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_life(t_data *data)
{
	pthread_mutex_lock(&data->mutex_life);
	if (data->alive == FALSE)
	{
		pthread_mutex_unlock(&data->mutex_life);
		return (FALSE);
	}
	pthread_mutex_unlock(&data->mutex_life);
	return (TRUE);
}

static void	death(t_data *data)
{
	pthread_mutex_lock(&data->mutex_life);
	data->alive = FALSE;
	pthread_mutex_unlock(&data->mutex_life);
}

int	hospital(t_philo *philo, t_data	*data)
{
	int	i;

	i = 0;
	while (i < philo->data->num_philo)
	{
		pthread_mutex_lock(&philo->data->mutex_meals);
		if (ph_get_time() - philo[i].ph_last_meal >= data->time_to_die)
		{
			pthread_mutex_unlock(&philo->data->mutex_meals);
			death(data);
			print_msg(&philo[i], 5);
			return (TRUE);
		}
		pthread_mutex_unlock(&philo->data->mutex_meals);
		i++;
	}
	return (FALSE);
}

void	*ph_life(void *data_struct)
{
	t_data	*data;
	t_philo	*philos;
	int		eaten;

	data = data_struct;
	philos = data->philo;
	while (1)
	{
		if (hospital(philos, data))
			return (NULL);
	}
	return (NULL);
}
