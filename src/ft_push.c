/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:58:52 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/08 16:53:44 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* pa (push a): Take the first element at 
the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top 
of a and put it at the top of b.
Do nothing if a is empty. */

void	ft_push(t_stack **src, t_stack **dst, char c)
{
	t_stack	*temp;

	if (*src == NULL || src == NULL || dst == NULL || *dst == NULL)
		return ;
	temp = *dst;
	*dst = (*dst)->next;
	temp->next = *src;
	*src = temp;
	if (c == 'a')
		ft_printf("pa\n");
	else if (c == 'b')
		ft_printf("pb\n");
}
