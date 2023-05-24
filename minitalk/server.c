/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezcakir <ezcakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:36:50 by ezcakir           #+#    #+#             */
/*   Updated: 2023/05/23 13:10:37 by ezcakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	put_signal(int s)
{
	static char		c = 0;
	static int		i = 128;

	if (s == SIGUSR1)
		c += i;
	i /= 2;
	if (i == 0)
	{
		write(1, &c, 1);
		c = 0;
		i = 128;
	}
}

int	main(void)
{
	ft_putnbr_fd(getpid(), 1);
	signal(SIGUSR1, put_signal);
	signal(SIGUSR2, put_signal);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
	return (0);
}
