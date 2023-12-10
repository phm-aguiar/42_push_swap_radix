/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:52:05 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/09 22:20:14 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	root;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		bits;

	if (argc == 1)
		exit(EXIT_FAILURE);
	ft_init_values(&root);
	stack_b = NULL;
	root.size = argc - 1;
	check_args(argv + 1, &root);
	bits = count_bits(argc - 1);
	stack_a = build_linked_list(&root, argv + 1);
	initialize_and_sort(&root, argv + 1);
	node_configuration(&stack_a, root.sorted, root.size);
	if (!is_lst_sorted(stack_a))
	{
		if ((argc - 1) <= 50 && (argc - 1) > 3)
			insertion_sort(&stack_a, &stack_b);
		else if ((argc - 1) <= 3)
			sort_three(&stack_a);
		else if ((argc - 1) > 50)
			radix(&stack_a, &stack_b, bits);
	}
	ft_success(&stack_a, &root);
}
