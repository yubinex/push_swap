/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhauck <jhauck@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 06:00:00 by jhauck            #+#    #+#             */
/*   Updated: 2026/06/24 06:00:00 by jhauck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

double	compute_disorder(t_stack *stack)
{
	t_node	*i;
	t_node	*j;
	int		mistakes;
	int		total;

	mistakes = 0;
	total = 0;
	i = stack->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total == 0)
		return (0.0);
	return ((double)mistakes / (double)total);
}

int	is_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node && node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

int	flag_eq(char *flag, char *name)
{
	int	i;

	i = 0;
	while (flag[i] && name[i] && flag[i] == name[i])
		i++;
	return (flag[i] == '\0' && name[i] == '\0');
}
