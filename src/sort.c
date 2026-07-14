/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaur <jubaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 06:00:00 by jhauck            #+#    #+#             */
/*   Updated: 2026/07/14 10:21:32 by jubaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_simple(t_state *state)
{
	bubble_sort(state);
}

void	sort_medium(t_state *state, t_chunk *c)
{
	push_chunks(state, c);
	push_back_sorted(state);
}

/*
** Dispatches to the right algorithm based on measured disorder:
** disorder < 0.2  -> simple  O(n^2)
** 0.2 <= d < 0.5  -> medium  O(n sqrt(n))
** disorder >= 0.5 -> complex O(n log n)
*/
void	sort_adaptive(t_state *state, t_chunk *c)
{
	if (state->disorder < 0.2)
		sort_simple(state);
	else if (state->disorder < 0.5)
		sort_medium(state, c);
	else
		sort_complex(state);
}
