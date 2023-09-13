/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezcakir <ezcakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:45:31 by ezcakir           #+#    #+#             */
/*   Updated: 2023/09/13 20:53:12 by ezcakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(char **av)
{
	t_stack	stack;
	int		size;
	int		i;

	i = -1;
	size = ft_ps_strlen(av);
	stack.a = malloc(sizeof(int) * size);
	if (!stack.a)
		return ;
	stack.size_a = size;
	stack.b = malloc(sizeof(int) * size);
	if (!stack.b)
	{
		free (stack.a);
		return ;
	}
	stack.size_b = 0;
	while (++i < size)
		stack.a[i] = ft_ps_atoi(av[i], stack.a);
	ft_check_repeat(stack.a, size);
	ft_sort(&stack, size);
	free (stack.a);
	free (stack.b);
}

int	av_control(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_strcmp(av[i], "") == 0)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	char	**data;

	data = NULL;
	if (av_control(av))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (ac > 1)
	{
		av++;
		if (ac == 2)
		{
			data = ft_split(*av, ' ');
			ft_push_swap(data);
		}
		else
			ft_push_swap(av);
	}
	if (data)
		free_(data);
	return (0);
}
