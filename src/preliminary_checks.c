/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preliminary_checks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:55:57 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/08 19:28:00 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
				ft_error(NULL, scr);
			j++;
		}
		i++;
	}
}

void	check_args(char **argv, t_ps *sca)
{
	char	**current;
	int		i;
	long	nbr;

	i = 0;
	nbr = 0;
	current = argv;
	while (i < sca->size - 1)
	{
		nbr = ft_atol(current[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			ft_error(NULL, sca);
		i++;
	}
	i = 0;
	while (i < sca->size - 1)
	{
		if (!ft_strisnumber(current[i]))
			ft_error(NULL, sca);
		i++;
	}
	check_repetitions(current, sca);
}
