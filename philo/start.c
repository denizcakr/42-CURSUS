/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezcakir <ezcakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:42:44 by ezcakir           #+#    #+#             */
/*   Updated: 2023/11/03 13:32:02 by ezcakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>
#include <stdio.h>

void	*start_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if ((philo->philo_id + 1) % 2 == 0)
		ft_sleep(10);
	pthread_mutex_lock(&philo->table->_die_control);
	while (philo->table->philo_dead)
	{
		pthread_mutex_unlock(&philo->table->_die_control);
		p_eat(philo);
		p_sleep(philo);
		p_think(philo);
		pthread_mutex_lock(&philo->table->_die_control);
	}
	pthread_mutex_unlock(&philo->table->_die_control);
	return (NULL);
}

void	p_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork[philo->right_fork]);
	pthread_mutex_lock(&philo->table->fork[philo->left_fork]);
	pthread_mutex_lock(&philo->table->write);
	if (philo->count_eat != philo->table->must_eat
		&& philo->table->philo_dead == 1)
	{
		printf("%llu %d has taken a fork \n", ms() - philo->table->start,
			philo->philo_id + 1);
		printf("%llu %d is eating \n", ms() - philo->table->start,
			philo->philo_id + 1);
	}
	pthread_mutex_unlock(&philo->table->write);
	ft_sleep(philo->table->time_to_eat);
	pthread_mutex_lock(&philo->table->_last_eat);
	philo->last_eat = ms();
	pthread_mutex_unlock(&philo->table->_last_eat);
	philo->count_eat++;
	pthread_mutex_unlock(&philo->table->fork[philo->right_fork]);
	pthread_mutex_unlock(&philo->table->fork[philo->left_fork]);
	if (philo->count_eat == philo->table->must_eat)
	{
		pthread_mutex_lock(&philo->table->_eat_control);
		philo->table->eat_control++;
		pthread_mutex_unlock(&philo->table->_eat_control);
	}
}

void	p_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->write);
	pthread_mutex_lock(&philo->table->_die_control);
	if (philo->count_eat != philo->table->must_eat
		&& philo->table->philo_dead != 0)
		printf("%llu %d is sleeping\n", ms() - philo->table->start,
			philo->philo_id + 1);
	pthread_mutex_unlock(&philo->table->_die_control);
	pthread_mutex_unlock(&philo->table->write);
	ft_sleep(philo->table->time_to_sleep);
}

void	p_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->write);
	pthread_mutex_lock(&philo->table->_die_control);
	if (philo->count_eat != philo->table->must_eat
		&& philo->table->philo_dead != 0)
		printf("%llu %d is thinking\n", ms() - philo->table->start,
			philo->philo_id + 1);
	pthread_mutex_unlock(&philo->table->_die_control);
	pthread_mutex_unlock(&philo->table->write);
}

void	start_threads(t_table *data)
{
	int			i;
	pthread_t	x;
	pthread_t	y;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_create(&data->philo[i].thread, NULL,
			start_philo, (void *)&data->philo[i]);
		i++;
	}
	pthread_create(&x, NULL, &die_control, data);
	pthread_create(&y, NULL, &eat_control, data);
	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (data->number_of_philosophers == 1)
			pthread_detach(data->philo[i].thread);
		else
			pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	pthread_join(x, NULL);
	pthread_join(y, NULL);
}
