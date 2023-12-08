/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:53:40 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/08 19:36:15 by phenriq2         ###   ########.fr       */
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
		ft_push(stack_a, stack_b, 'a');
		index++;
	}
}

void	radix(t_stack **stack_a, t_stack **stack_b, int bits)
{
	unsigned int	index;
	unsigned int	len_a;
	int				i;
	t_stack			*temp;

	i = 0;
	len_a = size_stk(*stack_a);
	temp = *stack_a;
	while (i < bits)
	{
		index = 0;
		while (index < len_a)
		{
			if ((temp->order >> i) % 2 == 1)
				ft_rotate(stack_a, 'a');
			else
				ft_push(stack_b, stack_a, 'b');
			index++;
			temp = (*stack_a);
		}
		push_back(stack_a, stack_b);
		i++;
	}
}
