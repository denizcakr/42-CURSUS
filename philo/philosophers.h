/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezcakir <ezcakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:56:15 by ezcakir           #+#    #+#             */
/*   Updated: 2023/11/03 13:30:51 by ezcakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdint.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				left_fork;
	int				right_fork;
	int				philo_id;
	int				count_eat;
	uint64_t		last_eat;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	int				p_sleep;
	int				p_eat;
	int				p_think;
	int				eat_control;
	int				philo_dead;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	uint64_t		start;
	pthread_mutex_t	_eat_control;
	pthread_mutex_t	_die_control;
	pthread_mutex_t	_last_eat;
	pthread_mutex_t	*fork;
	pthread_mutex_t	write;
	t_philo			*philo;
}	t_table;

pthread_mutex_t	*init(t_table *data);
int				ft_atoi(char *str);
int				number_check(int ac, char **av);
void			init_philos(t_table *data);
void			start_threads(t_table *data);
void			*start_philo(void *arg);
void			p_think(t_philo *philo);
void			p_eat(t_philo *philo);
void			p_sleep(t_philo *philo);
void			ft_sleep(uint64_t time);
void			*eat_control(void *arg);
void			*die_control(void *arg);
void			reset(int *i, int *j);
uint64_t		ms(void);

#endif
