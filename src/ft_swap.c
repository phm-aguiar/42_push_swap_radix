/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:59:09 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/09 22:21:21 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_stack **stack_a)
{
	t_stack	*temp_node;

	if (*stack_a && (*stack_a)->next)
	{
		temp_node = *stack_a;
		*stack_a = (*stack_a)->next;
		temp_node->next = (*stack_a)->next;
		(*stack_a)->next = temp_node;
	}
	ft_printf("sa\n");
}

void	swap_b(t_stack **stack_b)
{
	t_stack	*temp_node;

	if (*stack_b && (*stack_b)->next)
	{
		temp_node = *stack_b;
		*stack_b = (*stack_b)->next;
		temp_node->next = (*stack_b)->next;
		(*stack_b)->next = temp_node;
	}
	ft_printf("sb\n");
}

void	swap_ss(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_node;

	if (*stack_a && (*stack_a)->next)
	{
		temp_node = *stack_a;
		*stack_a = (*stack_a)->next;
		temp_node->next = (*stack_a)->next;
		(*stack_a)->next = temp_node;
	}
	if (*stack_b && (*stack_b)->next)
	{
		temp_node = *stack_b;
		*stack_b = (*stack_b)->next;
		temp_node->next = (*stack_b)->next;
		(*stack_b)->next = temp_node;
	}
	ft_printf("ss\n");
}
