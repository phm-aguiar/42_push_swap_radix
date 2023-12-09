/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:17:43 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/09 06:56:51 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_free_stack(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*temp;

	temp = NULL;
	current = NULL;
	current = *stack_a;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}

void	ft_success(t_stack **stack_a, t_ps *sfs)
{
	if (stack_a)
		ft_free_stack(stack_a);
	if (sfs->sorted)
		free(sfs->sorted);
	exit(EXIT_SUCCESS);
}

void	ft_error(t_stack **stack_a, t_ps *sr)
{
	ft_putstr_fd("Error\n", 2);
	if (*stack_a)
		ft_free_stack(stack_a);
	if (sr->sorted)
		free(sr->sorted);
	exit(EXIT_FAILURE);
}

int	size_stk(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	count_bits(int max)
{
	int	count;

	count = 0;
	while (max != 0)
	{
		max = max >> 1;
		count++;
	}
	return (count);
}
