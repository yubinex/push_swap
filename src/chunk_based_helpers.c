/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaur <jubaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 09:06:44 by jubaur            #+#    #+#             */
/*   Updated: 2026/07/14 09:13:20 by jubaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_chunk_pos(t_stack *a, int start, int end)
{
	t_node	*cur;
	int		pos;

	cur = a->top;
	pos = 0;
	while (cur)
	{
		if (cur->index >= start && cur->index <= end)
			return (pos);
		cur = cur->next;
		pos++;
	}
	return (-1);
}

int	ft_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

int	has_index_range(t_stack *stack, int start, int end)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp)
	{
		if (tmp->index >= start && tmp->index <= end)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	max_pos(t_stack *stack)
{
	t_node	*tmp;
	int		max;
	int		pos;
	int		i;

	tmp = stack->top;
	max = tmp->index;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->index > max)
		{
			max = tmp->index;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}
