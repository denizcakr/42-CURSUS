/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezcakir <ezcakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:01:04 by ezcakir           #+#    #+#             */
/*   Updated: 2023/11/03 13:31:31 by ezcakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>
#include <sys/time.h>

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
		{
			write(2, "Wrong Arguments!\n", 17);
			return (-1);
		}
	}
	i = 0;
	while (str[i] <= 32)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res);
}

int	ft_isdigit(int i)
{
	if (i >= '0' && i <= '9')
		return (1);
	return (0);
}

int	number_check(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][0] == '-')
			return (-1);
		if (!ft_isdigit(av[i][j]))
			return (1);
		while (av[i][j] && ft_isdigit(av[i][j]))
			j++;
		if (av[i][j])
			return (1);
		i++;
	}
	return (0);
}

uint64_t	ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (long)1000) + (tv.tv_usec / (long)1000));
}

void	ft_sleep(uint64_t time)
{
	uint64_t	sec;

	sec = ms();
	while (1)
	{
		if (ms() - sec >= time)
			break ;
		usleep(100);
	}
}
