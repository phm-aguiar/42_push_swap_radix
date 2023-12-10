/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_and_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:34:40 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/09 22:01:48 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	node_configuration(t_stack **stack, int *sorted, int size)
{
	t_stack	*current;
	int		j;

	current = *stack;
	while (current)
	{
		j = 0;
		while (j < size)
		{
			if (current->value == sorted[j])
			{
				current->order = j;
				break ;
			}
			j++;
		}
		current = current->next;
	}
}

void	swap_array(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	bubble_sort(int *array, int size)
{
	int	swap;
	int	i;

	swap = 1;
	while (swap)
	{
		swap = 0;
		i = 0;
		while (i < size - 1)
		{
			if (array[i] > array[i + 1])
			{
				swap_array(&array[i], &array[i + 1]);
				swap = 1;
				i++;
			}
			i++;
		}
	}
}

void	initialize_and_sort(t_ps *sias, char **argv)
{
	int	i;

	i = 0;
	sias->sorted = (int *)malloc(sizeof(int) * sias->size);
	if (sias->sorted == NULL)
		ft_error(NULL, sias);
	while (i < sias->size)
	{
		sias->sorted[i] = (int)ft_atol(argv[i]);
		i++;
	}
	bubble_sort(sias->sorted, sias->size);
}
