/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:58:52 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/09 22:21:04 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_node;

	if (stack_b == NULL || *stack_b == NULL)
		return ;
	temp_node = *stack_b;
	*stack_b = (*stack_b)->next;
	temp_node->next = *stack_a;
	*stack_a = temp_node;
	ft_printf("pa\n");
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_node;

	temp_node = *stack_a;
	*stack_a = (*stack_a)->next;
	temp_node->next = *stack_b;
	*stack_b = temp_node;
	ft_printf("pb\n");
}
