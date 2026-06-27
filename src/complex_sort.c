/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhauck <jhauck@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 00:05:03 by jhauck            #+#    #+#             */
/*   Updated: 2026/06/27 06:27:52 by jhauck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	rank_of_val(t_state *state, int val)
{
	t_node	*current;
	int		count;

	count = 0;
	current = state->a->top;
	while (current)
	{
		if (current->value < val)
			count++;
		current = current->next;
	}
	current = state->b->top;
	while (current)
	{
		if (current->value < val)
			count++;
		current = current->next;
	}
	return (count);
}

static void	radix_pass(t_state *state, int size, int bit)
{
	int	i;
	int	pushed;
	int	rank;

	i = 0;
	pushed = 0;
	while (i < size)
	{
		rank = rank_of_val(state, state->a->top->value);
		if ((rank >> bit) & 1)
			op_ra(state);
		else
		{
			pushed++;
			op_pb(state);
		}
		i++;
	}
	while (pushed)
	{
		op_pa(state);
		pushed--;
	}
}

void	sort_complex(t_state *state)
{
	int	size;
	int	bits;
	int	bit;

	size = state->a->size;
	bits = 0;
	while ((1 << bits) < size)
		bits++;
	bit = 0;
	while (bit < bits)
	{
		radix_pass(state, size, bit);
		bit++;
	}
}
