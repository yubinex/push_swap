/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhauck <jhauck@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 01:55:34 by jhauck            #+#    #+#             */
/*   Updated: 2026/06/24 02:02:46 by jhauck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_stack(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = tmp;
}

void	op_sa(t_state *state)
{
	swap_stack(state->a);
	state->ops.sa++;
	write(1, "sa\n", 3);
}

void	op_sb(t_state *state)
{
	swap_stack(state->b);
	state->ops.sb++;
	write(1, "sb\n", 3);
}

void	op_ss(t_state *state)
{
	swap_stack(state->a);
	swap_stack(state->b);
	state->ops.ss++;
	write(1, "ss\n", 3);
}
