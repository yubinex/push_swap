/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhauck <jhauck@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 17:17:18 by jhauck            #+#    #+#             */
/*   Updated: 2026/06/19 17:17:18 by jhauck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
	int				size;
}					t_stack;

typedef struct s_ops
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_ops;

typedef enum e_strategy
{
	STRATEGY_SIMPLE,
	STRATEGY_MEDIUM,
	STRATEGY_COMPLEX,
	STRATEGY_ADAPTIVE
}					t_strategy;

typedef struct s_state
{
	t_stack			*a;
	t_stack			*b;
	t_ops			ops;
	double			disorder;
	t_strategy		strategy;
	int				bench;
	int				silent;
}					t_state;

t_stack				*stack_new(void);
void				stack_push(t_stack *stack, int value);
int					stack_pop(t_stack *stack);
int					stack_peek(t_stack *stack);
void				stack_free(t_stack *stack);

void				op_sa(t_state *state);
void				op_sb(t_state *state);
void				op_ss(t_state *state);
void				op_pa(t_state *state);
void				op_pb(t_state *state);
void				op_ra(t_state *state);
void				op_rb(t_state *state);
void				op_rr(t_state *state);
void				op_rra(t_state *state);
void				op_rrb(t_state *state);
void				op_rrr(t_state *state);

#endif
