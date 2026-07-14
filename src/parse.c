/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhauck <jhauck@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 06:00:00 by jhauck            #+#    #+#             */
/*   Updated: 2026/07/15 00:19:39 by jhauck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	parse_int(char *s, int *out)
{
	long	val;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	if (s[i] == '-')
		sign = -1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!(s[i] >= '0' && s[i] <= '9'))
		return (0);
	val = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		val = val * 10 + (s[i] - '0');
		i++;
	}
	if (s[i] != '\0')
		return (0);
	val *= sign;
	if (val < INT_MIN || val > INT_MAX)
		return (0);
	*out = (int)val;
	return (1);
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

static int	process_arg_string(char *s, t_state *state)
{
	int		i;
	int		end;
	int		init;
	int		val;

	init = state->a->size;
	i = 0;
	while (s[i])
		i++;
	i--;
	while (i >= 0)
	{
		while (i >= 0 && (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
			i--;
		if (i < 0)
			break ;
		end = i;
		while (i >= 0 && s[i] != ' ' && !(s[i] >= 9 && s[i] <= 13))
			i--;
		s[end + 1] = '\0';
		if (!parse_int(&s[i + 1], &val))
			return (0);
		stack_push(state->a, val);
	}
	return (state->a->size > init);
}

static int	build_stack(int start, int argc, char **argv, t_state *state)
{
	int	i;

	i = argc - 1;
	while (i >= start)
	{
		if (!process_arg_string(argv[i], state))
			return (0);
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
