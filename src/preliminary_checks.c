/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preliminary_checks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:55:57 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/09 19:16:42 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stddef.h>

void	ft_init_values(t_ps *sfiv)
{
	sfiv->sorted = NULL;
	sfiv->size = 0;
}

static void	check_repetitions(char **argv, t_ps *scr)
{
	char	**current;
	int		i;
	int		j;

	i = 0;
	current = argv;
	while (i < scr->size - 1)
	{
		j = 0;
		while (j < scr->size)
		{
			if (!ft_strcmp(current[i], current[j]) && i != j)
			{
				ft_putstr_fd("Error\n", 2);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

static int	check_is_number(char *number)
{
	size_t	index;

	index = 0;
	if (number[index] == '\0')
		return (0);
	if (number[index] == '-' || number[index] == '+')
		index++;
	while (number[index])
	{
		if (!ft_isdigit(number[index]))
			return (0);
		index++;
	}
	return (1);
}

void	check_args(char **argv, t_ps *sca)
{
	char	**current;
	size_t	index;
	long	number;

	number = 0;
	index = 0;
	current = argv;
	while (current[index])
	{
		if (!check_is_number(current[index]))
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		number = ft_atol(current[index]);
		if (number > INT_MAX || number < INT_MIN)
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		index++;
	}
	current = argv;
	check_repetitions(current, sca);
}
