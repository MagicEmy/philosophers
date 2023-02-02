/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_lock_unlock.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:15:31 by emlicame          #+#    #+#             */
/*   Updated: 2023/02/02 14:09:53 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_lock_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex[philo->id - 1]);
	print_msg(philo, 1);
	pthread_mutex_lock(&philo->data->mutex[(philo->id) % \
	philo->data->num_philo]);
	print_msg(philo, 1);
	return (0);
}

void	mutex_unlock_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->mutex[philo->id - 1]);
	pthread_mutex_unlock(&philo->data->mutex[(philo->id) % \
	philo->data->num_philo]);
}
