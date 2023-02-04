/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_lock_unlock.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:15:31 by emlicame          #+#    #+#             */
/*   Updated: 2023/02/03 19:51:38 by emlicame         ###   ########.fr       */
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
