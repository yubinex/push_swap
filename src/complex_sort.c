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

static void	radix_pass(t_state *state, int size, int bit)
{
	int	i;
	int	pushed;

	i = 0;
	pushed = 0;
	while (i < size)
	{
		if ((state->a->top->index >> bit) & 1)
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
	assign_indices(state->a);
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
