/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 07:42:57 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/09 09:12:18 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->order;
	b = (*stack_a)->next->order;
	c = (*stack_a)->next->next->order;
	if (a > b && b < c && a < c)
		swap_a(stack_a);
	else if (a > b && b > c && a > c)
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	else if (a > b && b < c && a > c)
		rotate_a(stack_a);
	else if (a < b && b > c && a < c)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if (a < b && b > c && a > c)
		reverse_rotate_a(stack_a);
}

static int	find_min(t_stack *stack)
{
	int	min;

	min = stack->order;
	while (stack)
	{
		if (stack->order < min)
			min = stack->order;
		stack = stack->next;
	}
	return (min);
}

static int	dist_min_head(t_stack *stack, int min, int size_a)
{
	int	dist;

	dist = 0;
	while (stack)
	{
		if (stack->order == min)
			break ;
		dist++;
		stack = stack->next;
	}
	if (dist > (size_a + 1) / 2)
		dist = dist - size_a;
	return (dist);
}

void	insertion_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	len_a;
	int	size_a;

	len_a = size_stk(*stack_a);
	while (len_a > 3)
	{
		size_a = size_stk(*stack_a);
		min = find_min(*stack_a);
		while ((*stack_a)->order != min)
		{
			if (dist_min_head(*stack_a, min, size_a) > 0)
				rotate_a(stack_a);
			else
				reverse_rotate_a(stack_a);
		}
		push_b(stack_a, stack_b);
		len_a--;
	}
	sort_three(stack_a);
	while (*stack_b)
		push_a(stack_a, stack_b);
}
