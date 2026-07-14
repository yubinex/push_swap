/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhauck <jhauck@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 00:00:00 by jhauck            #+#    #+#             */
/*   Updated: 2026/07/15 00:00:00 by jhauck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort3(t_state *state)
{
	int	a;
	int	b;
	int	c;

	a = state->a->top->value;
	b = state->a->top->next->value;
	c = state->a->bottom->value;
	if (a > b && a > c)
		op_ra(state);
	else if (b > a && b > c)
		op_rra(state);
	if (state->a->top->value > state->a->top->next->value)
		op_sa(state);
}

static int	find_min_pos(t_stack *stack)
{
	t_node	*node;
	int		min;
	int		pos;
	int		i;

	node = stack->top;
	min = node->value;
	pos = 0;
	i = 0;
	while (node)
	{
		if (node->value < min)
		{
			min = node->value;
			pos = i;
		}
		node = node->next;
		i++;
	}
	return (pos);
}

static void	push_min(t_state *state)
{
	int	pos;

	pos = find_min_pos(state->a);
	if (pos <= state->a->size / 2)
		while (pos-- > 0)
			op_ra(state);
	else
	{
		pos = state->a->size - pos;
		while (pos-- > 0)
			op_rra(state);
	}
	op_pb(state);
}

void	sort_tiny(t_state *state)
{
	if (state->a->size == 2)
	{
		if (state->a->top->value > state->a->bottom->value)
			op_sa(state);
		return ;
	}
	if (state->a->size == 3)
	{
		sort3(state);
		return ;
	}
	if (state->a->size == 5)
		push_min(state);
	push_min(state);
	sort3(state);
	while (state->b->size)
		op_pa(state);
}
