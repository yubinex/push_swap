/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaur <jubaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 17:17:31 by jhauck            #+#    #+#             */
/*   Updated: 2026/07/14 10:26:04 by jubaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	init_state(t_state *state)
{
	state->a = stack_new();
	state->b = stack_new();
	state->ops.sa = 0;
	state->ops.sb = 0;
	state->ops.ss = 0;
	state->ops.pa = 0;
	state->ops.pb = 0;
	state->ops.ra = 0;
	state->ops.rb = 0;
	state->ops.rr = 0;
	state->ops.rra = 0;
	state->ops.rrb = 0;
	state->ops.rrr = 0;
	state->disorder = 0.0;
	state->strategy = STRATEGY_ADAPTIVE;
	state->bench = 0;
	state->silent = 0;
}

void	free_state(t_state *state)
{
	stack_free(state->a);
	stack_free(state->b);
}

void	error_exit(t_state *state)
{
	free_state(state);
	write(2, "Error\n", 6);
	exit(1);
}

static void	run_strategy(t_state *state, t_chunk *c)
{
	if (state->a->size <= 5 && state->strategy == STRATEGY_ADAPTIVE)
	{
		state->strategy = STRATEGY_TINY;
		sort_tiny(state);
		return ;
	}
	if (state->strategy == STRATEGY_SIMPLE)
		sort_simple(state);
	else if (state->strategy == STRATEGY_MEDIUM)
		sort_medium(state, c);
	else if (state->strategy == STRATEGY_COMPLEX)
		sort_complex(state);
	else
		sort_adaptive(state, c);
}

int	main(int argc, char **argv)
{
	t_state	state;
	t_chunk	c;

	if (argc < 2)
		return (0);
	init_state(&state);
	if (!parse_args(argc, argv, &state))
		error_exit(&state);
	if (is_sorted(state.a))
	{
		state.disorder = compute_disorder(state.a);
		print_bench(&state);
		free_state(&state);
		return (0);
	}
	state.disorder = compute_disorder(state.a);
	run_strategy(&state, &c);
	print_bench(&state);
	free_state(&state);
	return (0);
}
