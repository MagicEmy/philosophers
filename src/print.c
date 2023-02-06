/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:56:50 by emlicame          #+#    #+#             */
/*   Updated: 2023/02/04 18:04:37 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_print_msg(t_philo *philo, int case_pr)
{
	pthread_mutex_lock(&philo->data->mutex_life);
	if (case_pr == 0 && philo->data->alive == TRUE)
		printf (C_RED"%ld %d died\n"C_RESET, ph_get_time() - \
		philo->data->time_start, philo->id);
	else if (case_pr == 1 && philo->data->alive == TRUE)
		printf (C_ORANGE"%ld %d has taken a fork\n"C_RESET, ph_get_time() - \
		philo->data->time_start, philo->id);
	else if (case_pr == 2 && philo->data->alive == TRUE)
		printf (C_GREEN"%ld %d is eating\n"C_RESET, ph_get_time() - \
		philo->data->time_start, philo->id);
	else if (case_pr == 3 && philo->data->alive == TRUE)
		printf (C_DCYAN"%ld %d is sleeping\n"C_RESET, ph_get_time() - \
		philo->data->time_start, philo->id);
	else if (case_pr == 4 && philo->data->alive == TRUE)
		printf (C_VIOLET"%ld %d is thinking\n"C_RESET, ph_get_time() - \
		philo->data->time_start, philo->id);
	else if (case_pr == 5 && philo->data->alive == FALSE)
		printf (C_DMGNT"%ld %d died\n"C_RESET, ph_get_time() - \
		philo->data->time_start, philo->id);
	pthread_mutex_unlock(&philo->data->mutex_life);
}
