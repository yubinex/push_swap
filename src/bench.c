/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhauck <jhauck@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 00:00:00 by jhauck            #+#    #+#             */
/*   Updated: 2026/06/27 00:00:00 by jhauck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	write_int(int n)
{
	char	buf[11];
	int		i;

	i = 10;
	buf[i] = '\0';
	if (n == 0)
	{
		write(2, "0", 1);
		return ;
	}
	while (n > 0)
	{
		i--;
		buf[i] = '0' + (n % 10);
		n /= 10;
	}
	write(2, &buf[i], 10 - i);
}

static void	write_pct(double d)
{
	// TODO: implement percentage printing without printf
	(void)d;
	write(2, "?", 1);
}

static void	print_strategy(t_state *state)
{
	write(2, "[bench] strategy: ", 18);
	if (state->strategy == STRATEGY_SIMPLE)
		write(2, "Simple / O(n^2)", 15);
	else if (state->strategy == STRATEGY_MEDIUM)
		write(2, "Medium / O(n sqrt(n))", 21);
	else if (state->strategy == STRATEGY_COMPLEX)
		write(2, "Complex / O(n log n)", 20);
	else if (state->disorder < 0.2)
		write(2, "Adaptive / O(n^2)", 17);
	else if (state->disorder < 0.5)
		write(2, "Adaptive / O(n sqrt(n))", 23);
	else
		write(2, "Adaptive / O(n log n)", 21);
	write(2, "\n", 1);
}

static void	print_ops(t_ops *o)
{
	write(2, "[bench] sa: ", 12);
	write_int(o->sa);
	write(2, " sb: ", 5);
	write_int(o->sb);
	write(2, " ss: ", 5);
	write_int(o->ss);
	write(2, " pa: ", 5);
	write_int(o->pa);
	write(2, " pb: ", 5);
	write_int(o->pb);
	write(2, " ra: ", 5);
	write_int(o->ra);
	write(2, " rb: ", 5);
	write_int(o->rb);
	write(2, " rr: ", 5);
	write_int(o->rr);
	write(2, " rra: ", 6);
	write_int(o->rra);
	write(2, " rrb: ", 6);
	write_int(o->rrb);
	write(2, " rrr: ", 6);
	write_int(o->rrr);
	write(2, "\n", 1);
}

void	print_bench(t_state *state)
{
	t_ops	*o;
	int		total;

	if (!state->bench)
		return ;
	o = &state->ops;
	total = o->sa + o->sb + o->ss + o->pa + o->pb;
	total += o->ra + o->rb + o->rr + o->rra + o->rrb + o->rrr;
	write(2, "[bench] disorder: ", 18);
	write_pct(state->disorder);
	write(2, "\n", 1);
	print_strategy(state);
	write(2, "[bench] total_ops: ", 19);
	write_int(total);
	write(2, "\n", 1);
	print_ops(o);
}
