/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhauck <jhauck@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 06:00:00 by jhauck            #+#    #+#             */
/*   Updated: 2026/06/24 15:16:44 by jhauck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_simple(t_state *state)
{
	(void)state;
}

void	sort_medium(t_state *state)
{
	(void)state;
}

void	sort_complex(t_state *state)
{
	(void)state;
}

/*
** Dispatches to the right algorithm based on measured disorder:
** disorder < 0.2  -> simple  O(n^2)
** 0.2 <= d < 0.5  -> medium  O(n sqrt(n))
** disorder >= 0.5 -> complex O(n log n)
*/
void	sort_adaptive(t_state *state)
{
	if (state->disorder < 0.2)
		sort_simple(state);
	else if (state->disorder < 0.5)
		sort_medium(state);
	else
		sort_complex(state);
}
