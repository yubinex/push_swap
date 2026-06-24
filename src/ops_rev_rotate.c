/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhauck <jhauck@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 02:08:19 by jhauck            #+#    #+#             */
/*   Updated: 2026/06/24 05:47:21 by jhauck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
** Moves the bottom node to the top.
** Step 1: save old bottom, make second-to-last the new bottom, clear its next.
** Step 2: wire old bottom into the top: its next points to old top,
**         its prev is NULL, old top's prev points to it, update top.
*/
static void	rev_rotate_stack(t_stack *stack)
{
	t_node	*old_bottom;

	if (stack->size <= 1)
		return ;
	old_bottom = stack->bottom;
	stack->bottom = old_bottom->prev;
	stack->bottom->next = NULL;
	old_bottom->next = stack->top;
	old_bottom->prev = NULL;
	stack->top->prev = old_bottom;
	stack->top = old_bottom;
}

void	op_rra(t_state *state)
{
	rev_rotate_stack(state->a);
	state->ops.rra++;
	write(1, "rra\n", 4);
}

void	op_rrb(t_state *state)
{
	rev_rotate_stack(state->b);
	state->ops.rrb++;
	write(1, "rrb\n", 4);
}

void	op_rrr(t_state *state)
{
	rev_rotate_stack(state->a);
	rev_rotate_stack(state->b);
	state->ops.rrr++;
	write(1, "rrr\n", 4);
}
