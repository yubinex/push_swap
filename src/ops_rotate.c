/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhauck <jhauck@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 02:08:19 by jhauck            #+#    #+#             */
/*   Updated: 2026/06/24 05:43:20 by jhauck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
** Moves the top node to the bottom.
** Step 1: save old top, make second element the new top, clear its prev.
** Step 2: wire old top into the bottom: its prev points to old bottom,
**         its next is NULL, old bottom's next points to it, update bottom.
*/
static void	rotate_stack(t_stack *stack)
{
	t_node	*old_top;

	if (stack->size <= 1)
		return ;
	old_top = stack->top;
	stack->top = old_top->next;
	stack->top->prev = NULL;
	old_top->prev = stack->bottom;
	old_top->next = NULL;
	stack->bottom->next = old_top;
	stack->bottom = old_top;
}

void	op_ra(t_state *state)
{
	rotate_stack(state->a);
	state->ops.ra++;
	write(1, "ra\n", 3);
}

void	op_rb(t_state *state)
{
	rotate_stack(state->b);
	state->ops.rb++;
	write(1, "rb\n", 3);
}

void	op_rr(t_state *state)
{
	rotate_stack(state->a);
	rotate_stack(state->b);
	state->ops.rr++;
	write(1, "rr\n", 3);
}
