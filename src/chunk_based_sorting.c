/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based_sorting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaur <jubaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 09:02:30 by jubaur            #+#    #+#             */
/*   Updated: 2026/07/14 11:31:15 by jubaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_chunks(t_state *state, t_chunk *c)
{
	int	chunk;

	c->size = state->a->size;
	assign_indices(state->a);
	c->chunks = ft_sqrt(c->size);
	if (c->chunks == 0)
		c->chunks = 1;
	c->chunk_size = c->size / c->chunks;
	chunk = 0;
	while (chunk < c->chunks)
	{
		c->start = chunk * c->chunk_size;
		if (chunk == c->chunks - 1)
			c->end = c->size - 1;
		else
			c->end = (chunk + 1) * c->chunk_size - 1;
		while (has_index_range(state->a, c->start, c->end))
		{
			chunks_rotate(state, c);
		}
		chunk++;
	}
}

void	chunks_rotate(t_state *state, t_chunk *c)
{
	int	pos;

	pos = find_chunk_pos(state->a, c->start, c->end);
	if (pos <= state->a->size / 2)
	{
		while (pos--)
			op_ra(state);
	}
	else
	{
		pos = state->a->size - pos;
		while (pos--)
			op_rra(state);
	}
	op_pb(state);
	if (state->b->top->index < (c->start + c->end) / 2)
		op_rb(state);
}

// static void	init_chunks(t_state *state, t_chunk *c)
// {
// 	c->size = state->a->size;
// 	assign_indices(state->a);
// 	c->chunks = ft_sqrt(c->size);
// 	if (!c->chunks)
// 		c->chunks = 1;
// 	c->chunk_size = c->size / c->chunks;
// }

// void	push_chunks(t_state *state)
// {
// 	t_chunk	c;
// 	int		chunk;

// 	init_chunks(state, &c);
// 	chunk = 0;
// 	while (chunk < c.chunks)
// 	{
// 		c.start = chunk * c.chunk_size;
// 		if (chunk == c.chunks - 1)
// 			c.end = c.size - 1;
// 		else
// 			c.end = (chunk + 1) * c.chunk_size - 1;
// 		push_chunk(state, c.start, c.end);
// 		chunk++;
// 	}
// }

void	push_back_sorted(t_state *state)
{
	int	pos;

	while (state->b->size)
	{
		pos = max_pos(state->b);
		if (pos <= state->b->size / 2)
			while (pos--)
				op_rb(state);
		else
		{
			pos = state->b->size - pos;
			while (pos--)
				op_rrb(state);
		}
		op_pa(state);
	}
}
