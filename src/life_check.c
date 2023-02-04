/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:38:49 by emlicame          #+#    #+#             */
/*   Updated: 2023/02/03 19:50:04 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_life(t_data *data)
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

static bool	ph_kanteen(t_philo *philo, t_data	*data)
{
	int	i;
	int	total_meals;

	i = 0;
	total_meals = 0;
	while (i < philo->data->num_philo)
	{
		pthread_mutex_lock(&philo->data->mutex_meals);
		if (philo[i].meals_eaten == data->num_meals)
			total_meals++;
		pthread_mutex_unlock(&philo->data->mutex_meals);
		if (total_meals == data->num_philo)
			return (death(data), TRUE);
		i++;
	}
	return (FALSE);
}

static bool	ph_hospital(t_philo *philo, t_data	*data)
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
			ph_print_msg(&philo[i], 5);
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
	t_philo	*philo;
	int		count_meals;

	data = data_struct;
	philo = data->philo;
	count_meals = 0;
	while (1)
	{
		if (ph_hospital(philo, data))
			return (NULL);
		if (data->num_meals > 0 && ph_kanteen(philo, data))
			return (NULL);
	}
	return (NULL);
}
