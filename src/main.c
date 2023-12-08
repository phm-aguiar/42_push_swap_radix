/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:52:05 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/08 19:31:00 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	print_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d ", tab[i]);
		i++;
	}
}

static void	ft_print_stack(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		ft_printf("value:%d order:%d \n", temp->value, temp->order);
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	t_ps	root;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		bits;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	bits = number_bits(argc);
	ft_init_values(&root);
	root.size = argc - 1;
	check_args(argv + 1, &root);
	stack_a = build_linked_list(&root, argv + 1);
	initialize_and_sort(&root, argv + 1);
	node_configuration(&stack_a, root.sorted, root.size);
	ft_print_stack(stack_a);
	print_tab(root.sorted, root.size);
	radix(&stack_a, &stack_b, bits);
	ft_success(&stack_a, &root);
}
