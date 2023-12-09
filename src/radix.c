/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:53:40 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/09 07:34:00 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_back(t_stack **stack_a, t_stack **stack_b)
{
	unsigned int	index;
	unsigned int	len_b;

	index = 0;
	len_b = size_stk(*stack_b);
	while (index < len_b)
	{
		push_a(stack_a, stack_b);
		index++;
	}
}

void	radix(t_stack **stack_a, t_stack **stack_b, int bits)
{
	unsigned int	index;
	unsigned int	len_a;
	int				i;

	i = 0;
	len_a = size_stk(*stack_a);
	while (i < bits)
	{
		index = 0;
		while (index < len_a)
		{
			if (((*stack_a)->order >> i) % 2 == 1)
			{
				rotate_a(stack_a);
			}
			else
				push_b(stack_a, stack_b);
			index++;
			(*stack_a) = (*stack_a);
		}
		push_back(stack_a, stack_b);
		i++;
	}
}
