/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezcakir <ezcakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:47:27 by ezcakir           #+#    #+#             */
/*   Updated: 2023/09/13 20:57:10 by ezcakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_error(t_stack *stack, int num)
{
	free(stack->a);
	free(stack->b);
	if (num)
		write(1, "Error\n", 6);
	exit(1);
}

void	exec_instruction(t_stack *stack, char *instruction)
{
	if (!ft_strcmp(instruction, "sa\n"))
		sa(stack, 1);
	else if (!ft_strcmp(instruction, "sb\n"))
		sb(stack, 1);
	else if (!ft_strcmp(instruction, "ra\n"))
		ra(stack, 1);
	else if (!ft_strcmp(instruction, "rb\n"))
		rb(stack, 1);
	else if (!ft_strcmp(instruction, "rra\n"))
		rra(stack, 1);
	else if (!ft_strcmp(instruction, "rrb\n"))
		rrb(stack, 1);
	else if (!ft_strcmp(instruction, "pa\n"))
		pa(stack, 1);
	else if (!ft_strcmp(instruction, "pb\n"))
		pb(stack, 1);
	else
		free_error(stack, 1);
}

void	ft_checkchecker(t_stack *stack)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		exec_instruction(stack, str);
		free(str);
		str = get_next_line(0);
	}
	if (ft_checked_sorted(stack->a, stack->size_a, 0) && stack->size_b == 0)
		write(1, "\033[0;32mOK\n", 10);
	else
		write(1, "\033[0;32mKO\n", 10);
	free_error(stack, 0);
}

void	ft_checker(char **av)
{
	t_stack	stack;
	int		size;
	int		i;

	i = 0;
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
	while (i < size)
	{
		stack.a[i] = ft_ps_atoi(av[i], stack.a);
		i++;
	}
	ft_check_repeat(stack.a, size);
	ft_checkchecker(&stack);
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
	if (av_control(av))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (ac > 1)
	{
		av++;
		if (ac == 2)
			av = ft_split(*av, ' ');
		ft_checker(av);
	}
	return (0);
}
