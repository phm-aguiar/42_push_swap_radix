/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:13:42 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/08 19:24:00 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

/**
 * @brief Struct to store the stack
 * @param value The value of the stack
 * @param next The next stack
 * @param order The index of the stack
 */
typedef struct s_stack
{
	int				value;
	int				order;
	struct s_stack	*next;

}					t_stack;

/**
 * @brief struct to store my variables for push_swap
 * @param sorted The sorted array
 * @param size The size of the stack
 */
typedef struct s_push_swap
{
	int				*sorted;
	int				size;
}					t_ps;

// my label f

// my aliases for my structures in each function
// are declared as the initials of each function

// preliminary_checks.c
void				ft_init_values(t_ps *sfiv);
void				check_args(char **argv, t_ps *sca);

// utils.c
void				ft_error(t_stack **stack, t_ps *sfe);
void				ft_success(t_stack **stack, t_ps *sfs);
int					find_repetions(long a, long b);
int					size_stk(t_stack *stack);
int					number_bits(int argc);

// inicialize_linked_list.c

t_stack				*build_linked_list(t_ps *root, char **argv);
t_stack				*make_new_node(t_ps *smnn);

// populate_and_sort.c

void				initialize_and_sort(t_ps *sias, char **argv);
void				node_configuration(t_stack **stack, int *sorted, int size);

// radix.c

void				radix(t_stack **stack_a, t_stack **stack_b, int bits);

// operations

// pa and pb
void				ft_push(t_stack **src, t_stack **dst, char c);
// ra and rb
void				ft_rotate(t_stack **stack, char c);
// rr
void				ft_rotate_ab(t_stack **a, t_stack **b);
// rra and rrb
void				ft_rev_rotate(t_stack **stack, char c);
// rrr
void				ft_rev_rotate_ab(t_stack **a, t_stack **b);
// sa and sb
void				ft_swap(t_stack **a, char c);
// ss
void				ft_swap_ab(t_stack **a, t_stack **b);

#endif