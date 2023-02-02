/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:28:29 by emlicame          #+#    #+#             */
/*   Updated: 2023/02/01 13:14:59 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	ft_atol(const char *str)
{
	long int	number;
	int			sign;
	int			i;

	number = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number += (int)str[i] - '0';
		i++;
	}
	return (number * sign);
}

int	check_args(int argc, char **argv)
{
	if (ft_atol(argv[1]) < 1 || ft_atol(argv[1]) > 200)
		return (error(ERROR_ARGS_PH), 1);
	if (ft_atol(argv[1]) < 1 || ft_atol(argv[2]) < 1 || ft_atol(argv[3]) < 1 \
		|| ft_atol(argv[4]) < 1)
		return (error(ERROR_ARGS), 1);
	if (argc == 6 && ft_atol(argv[5]) < 1)
		return (error(ERROR_ARGS), 1);
	return (0);
}

t_data	*data_init(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (error(ERROR_MALLOC), NULL);
	data->num_philo = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_sleep = ft_atol(argv[4]);
	data->num_meals = 0;
	if (argc == 6)
		data->num_meals = ft_atol(argv[5]);
	data->alive = TRUE;
	data->philo = malloc(sizeof(t_philo) * data->num_philo + 1);
	if (!data->philo)
		return (error(ERROR_MALLOC), NULL);
	data->mutex = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!data->mutex)
		return (error(ERROR_MALLOC), NULL);
	return (data);
}
