/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_linked_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:42:19 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/09 22:19:37 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_lst_sorted(t_stack *stack)
{
	t_stack	*temp;

	if (stack == NULL)
		return (0);
	temp = stack;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

t_stack	*ft_last(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_stack	*make_new_node(void)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	return (node);
}

t_stack	*build_linked_list(t_ps *sbll, char **argv)
{
	int		i;
	t_stack	*head;
	t_stack	*node;

	head = make_new_node();
	if (head == NULL)
		ft_error(&head, sbll);
	node = head;
	i = 0;
	while (i < sbll->size)
	{
		node->value = (int)ft_atol(argv[i]);
		node->order = 0;
		if (i < sbll->size - 1)
		{
			node->next = make_new_node();
			if (node->next == NULL)
				ft_error(&head, sbll);
			node = node->next;
		}
		i++;
	}
	if (node)
		node->next = NULL;
	return (head);
}
