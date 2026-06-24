/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhauck <jhauck@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 01:46:55 by jhauck            #+#    #+#             */
/*   Updated: 2026/06/24 05:23:58 by jhauck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	op_pa(t_state *state)
{
	if (!state->b->size)
		return ;
	stack_push(state->a, stack_pop(state->b));
	state->ops.pa++;
	write(1, "pa\n", 3);
}

void	op_pb(t_state *state)
{
	if (!state->a->size)
		return ;
	stack_push(state->b, stack_pop(state->a));
	state->ops.pb++;
	write(1, "pb\n", 3);
}
