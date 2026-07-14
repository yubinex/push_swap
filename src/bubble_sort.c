/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaur <jubaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 09:05:29 by jubaur            #+#    #+#             */
/*   Updated: 2026/07/14 09:31:42 by jubaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	stack_size(t_stack *a)
{
	int		size;
	t_node	*current;

	size = 0;
	current = a->top;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

void	bubble_sort(t_state *state)
{
	int		size;
	int		i;

	size = stack_size(state->a);
	i = 0;
	while (i < size - 1)
	{
		bubble_rotate(state, i);
		i++;
	}
}

void	bubble_rotate(t_state *state, int i)
{
	int		j;
	t_node	*current;
	int		size;

	size = stack_size(state->a);
	if (is_sorted(state->a))
		return ;
	j = 0;
	current = state->a->top;
	while (j < size - i - 1)
	{
		if (current->value > current->next->value)
			op_sa(state);
		op_ra(state);
		j++;
		current = state->a->top;
	}
	j = 0;
	while (j < size - i - 1)
	{
		op_rra(state);
		j++;
	}
}
