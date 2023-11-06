/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_die_and_eat.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezcakir <ezcakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:37:07 by ezcakir           #+#    #+#             */
/*   Updated: 2023/11/03 13:26:15 by ezcakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>
#include <unistd.h>

void	a_philo_die_control(t_table *data)
{
	pthread_mutex_lock(&data->write);
	printf("%llu %d died\n", ms() - data->start, data->philo->philo_id + 1);
	pthread_mutex_unlock(&data->write);
	pthread_mutex_lock(&data->_die_control);
	data->philo_dead = 0;
	pthread_mutex_unlock(&data->_die_control);
}

void	*eat_control(void *arg)
{
	t_table		*data;

	data = (t_table *)arg;
	while (data->must_eat != -1)
	{
		pthread_mutex_lock(&data->_eat_control);
		if (data->number_of_philosophers == data->eat_control)
		{
			pthread_mutex_unlock(&data->_eat_control);
			pthread_mutex_lock(&data->_die_control);
			data->philo_dead = 0;
			pthread_mutex_unlock(&data->_die_control);
			break ;
		}
		pthread_mutex_unlock(&data->_eat_control);
	}
	return (NULL);
}

int	many_philo_die(t_table *data, int i)
{
	pthread_mutex_lock(&data->_last_eat);
	if (ms() - data->philo[i].last_eat
		>= (uint64_t)data->time_to_die)
	{
		pthread_mutex_unlock(&data->_last_eat);
		pthread_mutex_lock(&data->write);
		printf("%llu %d died\n", ms()
			- data->start, data->philo->philo_id + 1);
		pthread_mutex_unlock(&data->write);
		pthread_mutex_lock(&data->_die_control);
		data->philo_dead = 0;
		pthread_mutex_unlock(&data->_die_control);
		return (1);
	}
	return (0);
}

void	*die_control(void *arg)
{
	t_table	*data;
	int		i;
	int		j;

	i = 0;
	j = 1;
	data = (t_table *)arg;
	if (data->number_of_philosophers == 1)
		a_philo_die_control(data);
	pthread_mutex_lock(&data->_eat_control);
	while (data->number_of_philosophers > 1
		&& data->number_of_philosophers != data->eat_control)
	{
		pthread_mutex_unlock(&data->_eat_control);
		if (many_philo_die(data, i))
			break ;
		pthread_mutex_unlock(&data->_last_eat);
		i++;
		if (++j > data->number_of_philosophers)
			reset(&i, &j);
		usleep(100);
		pthread_mutex_lock(&data->_eat_control);
	}
	pthread_mutex_unlock(&data->_eat_control);
	return (NULL);
}
