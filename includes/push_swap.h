/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:13:42 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/09 22:17:44 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

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

// preliminary_checks.c
void				ft_init_values(t_ps *sfiv);
void				check_args(char **argv, t_ps *sca);
void				check_null_string(char **argv);

// utils.c
void				ft_error(t_stack **stack, t_ps *sfe);
void				ft_success(t_stack **stack, t_ps *sfs);
int					find_repetions(long a, long b);
int					size_stk(t_stack *stack);
int					count_bits(int max);

// inicialize_linked_list.c

t_stack				*build_linked_list(t_ps *root, char **argv);
t_stack				*make_new_node(void);
t_stack				*ft_last(t_stack *lst);
int					is_lst_sorted(t_stack *stack);

// populate_and_sort.c

void				initialize_and_sort(t_ps *sias, char **argv);
void				node_configuration(t_stack **stack, int *sorted, int size);

// radix.c

void				radix(t_stack **stack_a, t_stack **stack_b, int bits);

// insertion.c

void				sort_three(t_stack **stack_a);
void				sort_five(t_stack **stack_a, t_stack **stack_b);
void				insertion_sort(t_stack **stack_a, t_stack **stack_b);

// operations

// pa and pb
void				push_a(t_stack **stack_a, t_stack **stack_b);
void				push_b(t_stack **stack_a, t_stack **stack_b);
// ra and rb and rr
void				rotate_a(t_stack **stack_a);
void				rotate_b(t_stack **stack_b);
void				rotate_rr(t_stack **stack_a, t_stack **stack_b);
// rra and rrb and rrr
void				reverse_rotate_a(t_stack **stack_a);
void				reverse_rotate_b(t_stack **stack_b);
void				reverse_rotate_rrr(t_stack **stack_a, t_stack **stack_b);
// sa and sb and ss
void				swap_a(t_stack **stack_a);
void				swap_b(t_stack **stack_b);
void				swap_ss(t_stack **stack_a, t_stack **stack_b);

#endif