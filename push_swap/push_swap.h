/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezcakir <ezcakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:45:55 by ezcakir           #+#    #+#             */
/*   Updated: 2023/09/16 16:31:28 by ezcakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stack;

//checker
void	ft_checker(char **av);
void	ft_checkchecker(t_stack *stack);
void	free_error(t_stack *stack, int num);
void	exec_instruction(t_stack *stack, char *instruction);
//get_next_line
char	*get_next_line(int fd);
//functions1
void	ft_error(int *stack);
int		ft_ps_strlen(char **str);
int		ft_ps_atoi(char *str, int *stack);
void	ft_check_repeat(int *stack, int size);
//functions2
int		ft_checked_sorted(int *stack_a, int size, int flag);
int		ft_sort(t_stack *stack, int size);
void	ft_sort_three(t_stack *s);
void	ft_sort_int_tmp(int *tmp_stack, int size);
//functions3
void	ft_quicksort_3(t_stack *stack, int len);
int		ft_sort_small_b(t_stack *s, int len);
int		ft_push(t_stack *stack, int len, int operation);
int		ft_get_middle(int *pivot, int *stack_a, int size);
int		ft_quicksort_a(t_stack *stack, int len, int count);
int		ft_quicksort_b(t_stack *stack, int len, int count);
//rules a
void	sa(t_stack *stack, int print);
void	rra(t_stack *stack, int print);
void	ra(t_stack *stack, int print);
void	pa(t_stack *stack, int print);
//rules b
void	pb(t_stack *stack, int print);
void	sb(t_stack	*stack, int print);
void	rb(t_stack	*stack, int print);
void	rrb(t_stack *stack, int print);

void	ft_push_swap(char **av);

size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
void	free_(char **data);
int		ft_strcmp(char *s1, char *s2);
int		av_control(char **av);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_new_left_str(char *left_str);
char	**ft_split(char const *s, char c);
#endif