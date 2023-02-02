/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:56:50 by emlicame          #+#    #+#             */
/*   Updated: 2023/02/02 15:28:45 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_msg(t_philo *philo, int case_pr)
{
	pthread_mutex_lock(&philo->data->mutex_life);
	if (case_pr == 0 && philo->data->alive == TRUE)
		printf ("%ld %d died\n", ph_get_time() - philo->data->time_start, \
		philo->id);
	else if (case_pr == 1 && philo->data->alive == TRUE)
		printf ("%ld %d has taken a fork\n", ph_get_time() - \
		philo->data->time_start, philo->id);
	else if (case_pr == 2 && philo->data->alive == TRUE)
		printf ("%ld %d is eating\n", ph_get_time() - philo->data->time_start, \
		philo->id);
	else if (case_pr == 3 && philo->data->alive == TRUE)
		printf ("%ld %d is sleeping\n", ph_get_time() - philo->data->time_start, \
		philo->id);
	else if (case_pr == 4 && philo->data->alive == TRUE)
		printf ("%ld %d is thinking\n", ph_get_time() - philo->data->time_start, \
		philo->id);
	else if (case_pr == 5 && philo->data->alive == FALSE)
		printf ("%ld %d died\n", ph_get_time() - philo->data->time_start, \
		philo->id);
	pthread_mutex_unlock(&philo->data->mutex_life);
	return (0);
}
