/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezcakir <ezcakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:32:12 by ezcakir           #+#    #+#             */
/*   Updated: 2023/11/03 16:16:04 by ezcakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t	*init_mutex(t_table *data)
{
	int				i;
	pthread_mutex_t	*tmp;

	i = 0;
	tmp = malloc(sizeof(t_table) * data->number_of_philosophers);
	if (!tmp)
	{
		free(data);
		return (NULL);
	}
	while (i < data->number_of_philosophers)
	{
		if (pthread_mutex_init(&tmp[i], NULL))
			return (0);
		i++;
	}
	if (pthread_mutex_init(&data->write, NULL))
		return (free(tmp), NULL);
	if (pthread_mutex_init(&data->_die_control, NULL))
		return (free(tmp), pthread_mutex_destroy(&data->write), NULL);
	if (pthread_mutex_init(&data->_last_eat, NULL))
		return (free(tmp), pthread_mutex_destroy(&data->write),
			pthread_mutex_destroy(&data->_die_control), NULL);
	return (tmp);
}

t_table	*init_arg(char **av)
{
	t_table	*data;

	data = malloc(sizeof(t_table));
	if (!data)
		return (NULL);
	data->number_of_philosophers = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->must_eat = ft_atoi(av[5]);
	else
		data->must_eat = -1;
	data->fork = init_mutex(data);
	if (!data->fork || data->fork == 0)
		return (free(data), NULL);
	data->philo_dead = 1;
	data->start = ms();
	data->eat_control = 0;
	return (data);
}

void	destroy(t_table *data)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->_last_eat);
	pthread_mutex_destroy(&data->_eat_control);
	pthread_mutex_destroy(&data->_die_control);
	while (++i < data->number_of_philosophers)
		pthread_mutex_destroy(&data->fork[i]);
	free(data->philo);
	free(data->fork);
	free(data);
}

int	main(int ac, char **av)
{
	t_table	*data;
	int		x;

	if ((ac < 5) || (ac > 6))
	{
		write(2, "Wrong Argument!\n", 16);
		return (0);
	}
	x = number_check(ac, av);
	if (x == -1 || x)
	{
		if (x == -1)
			write(2, "Only Positive Number!\n", 22);
		else if (x)
			write(2, "Only Number!\n", 13);
		return (0);
	}
	data = init_arg(av);
	if (!data)
		return (0);
	init_philos(data);
	start_threads(data);
	destroy(data);
}
