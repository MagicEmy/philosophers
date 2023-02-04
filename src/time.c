/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:47:08 by emlicame          #+#    #+#             */
/*   Updated: 2023/01/18 16:43:17 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ph_get_time(void)
{
	struct timeval	time;
	long			now;

	gettimeofday(&time, NULL);
	now = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (now);
}

void	ph_usleep(long ms)
{
	long	start;

	start = ph_get_time();
	while ((ph_get_time() - start) < ms)
		usleep(450);
}
