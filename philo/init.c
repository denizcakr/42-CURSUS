/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezcakir <ezcakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:19:23 by ezcakir           #+#    #+#             */
/*   Updated: 2023/11/03 13:32:43 by ezcakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

void	init_philos(t_table *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->number_of_philosophers);
	if (!data->philo)
	{
		free(data->fork);
		free(data);
		return ;
	}
	while (i < data->number_of_philosophers)
	{
		data->philo[i].philo_id = i;
		data->philo[i].right_fork = i;
		data->philo[i].left_fork = (i + 1) % data->number_of_philosophers;
		data->philo[i].table = data;
		data->philo[i].count_eat = 0;
		data->philo[i].last_eat = ms();
		i++;
	}
}
