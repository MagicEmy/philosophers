/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:51:03 by emanuela          #+#    #+#             */
/*   Updated: 2023/02/06 21:37:08 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error(char *msg)
{
	printf("Error: %s\n", msg);
}

static int	ph_check_args(int argc, char **argv)
{
	if (ph_atol(argv[1]) < 1 || ph_atol(argv[1]) > 200)
		return (error(ERROR_ARGS_PH), 1);
	if (ph_atol(argv[1]) < 1 || ph_atol(argv[2]) < 1 || ph_atol(argv[3]) < 1 \
		|| ph_atol(argv[4]) < 1)
		return (error(ERROR_ARGS), 1);
	if (argc == 6 && ph_atol(argv[5]) < 1)
		return (error(ERROR_ARGS), 1);
	return (0);
}

static void	ph_free(t_data *data)
{
	free (data->philo);
	free (data->mutex);
	free (data);
}

int	main(int argc, char **argv)
{
	t_data			*data;

	data = NULL;
	if (argc < 5 || argc > 6)
		return (error("Wrong number of arguments"), 1);
	if (ph_check_args(argc, argv))
		return (0);
	data = ph_data_init(argc, argv);
	if (!data)
		return (1);
	if (ph_mutex_init(data))
		return (ph_free(data), 1);
	if (ph_threads_and_routine(data))
		return (ph_mutex_destroy(data), ph_free(data), 1);
	if (ph_mutex_destroy(data))
		return (ph_free(data), 1);
	ph_free(data);
	return (0);
}

// void exitcheck()
// {
// 	system("leaks philo");
// }
// atexit(exitcheck);