/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhauck <jhauck@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 01:55:34 by jhauck            #+#    #+#             */
/*   Updated: 2026/06/23 06:47:40 by jhauck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_stack(t_stack *s)
{
	int	tmp;

	if (s->size < 2)
		return ;
	tmp = s->top->value;
	s->top->value = s->top->next->value;
	s->top->next->value = tmp;
}

void	op_sa(t_state *s)
{
	swap_stack(s->a);
	s->ops.sa++;
	write(1, "sa\n", 3);
}

void	op_sb(t_state *s)
{
	swap_stack(s->b);
	s->ops.sb++;
	write(1, "sb\n", 3);
}

void	op_ss(t_state *s)
{
	swap_stack(s->a);
	swap_stack(s->b);
	s->ops.ss++;
	write(1, "ss\n", 3);
}
