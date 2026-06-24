/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhauck <jhauck@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 06:00:00 by jhauck            #+#    #+#             */
/*   Updated: 2026/06/24 06:00:00 by jhauck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static long	str_to_long(char *s)
{
	long	val;
	int		sign;
	int		i;

	val = 0;
	sign = 1;
	i = 0;
	if (s[0] == '-')
		sign = -1;
	if (s[0] == '+' || s[0] == '-')
		i = 1;
	while (s[i] >= '0' && s[i] <= '9')
	{
		val = val * 10 + (s[i] - '0');
		i++;
	}
	return (val * sign);
}

static int	valid_int_str(char *s)
{
	int		i;
	int		start;
	long	val;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	start = i;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (i == start || s[i] != '\0')
		return (0);
	if (i - start > 10)
		return (0);
	val = str_to_long(s);
	return (val >= INT_MIN && val <= INT_MAX);
}

static int	has_duplicate(t_stack *stack)
{
	t_node	*i;
	t_node	*j;

	i = stack->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

static int	build_stack(int start, int argc, char **argv, t_state *state)
{
	int		i;
	long	val;

	i = argc - 1;
	while (i >= start)
	{
		if (!valid_int_str(argv[i]))
			return (0);
		val = str_to_long(argv[i]);
		stack_push(state->a, (int)val);
		i--;
	}
	return (!has_duplicate(state->a));
}

int	parse_args(int argc, char **argv, t_state *state)
{
	int	i;

	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2])
	{
		if (argv[i][2] == 's')
			state->strategy = STRATEGY_SIMPLE;
		else if (argv[i][2] == 'm')
			state->strategy = STRATEGY_MEDIUM;
		else if (argv[i][2] == 'c')
			state->strategy = STRATEGY_COMPLEX;
		else if (argv[i][2] == 'a')
			state->strategy = STRATEGY_ADAPTIVE;
		else if (argv[i][2] == 'b')
			state->bench = 1;
		else
			return (0);
		i++;
	}
	if (i >= argc)
		return (1);
	return (build_stack(i, argc, argv, state));
}
