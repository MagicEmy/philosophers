/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:51:03 by emanuela          #+#    #+#             */
/*   Updated: 2023/02/02 11:53:54 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error(char *msg)
{
	printf("Error: %s\n", msg);
}

int	ph_threads_and_routine(t_data *data)
{
	if (ph_create_philo(data))
		return (1);
	if (ph_join_philo(data))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data			*data;

	data = NULL;
	if (argc < 5 || argc > 6)
		return (error("Wrong number of arguments"), 1);
	usleep (500);
	if (check_args(argc, argv))
		return (0);
	data = data_init(argc, argv);
	if (!data)
		return (free(data), 1);
	if (ph_mutex_init(data))
		return (free(data), 1);
	if (ph_threads_and_routine(data))
		return (free(data), ph_mutex_destroy(data), 1);
	if (ph_mutex_destroy(data))
		return (free(data), 1);
	free (data);
	return (0);
}

// system ("leaks -q philo");
/*
 - free threads and th*
 - free mutex *
 - free data
*/