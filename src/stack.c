/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhauck <jhauck@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 17:17:42 by jhauck            #+#    #+#             */
/*   Updated: 2026/06/19 17:17:42 by jhauck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*stack_new(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return (stack);
}

void	stack_push(t_stack *stack, int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->value = value;
	node->prev = NULL;
	node->next = stack->top;
	if (stack->top)
		stack->top->prev = node;
	else
		stack->bottom = node;
	stack->top = node;
	stack->size++;
}

int	stack_pop(t_stack *stack)
{
	t_node	*node;
	int		value;

	if (!stack->top)
		return (0);
	node = stack->top;
	value = node->value;
	stack->top = node->next;
	if (stack->top)
		stack->top->prev = NULL;
	else
		stack->bottom = NULL;
	free(node);
	stack->size--;
	return (value);
}

int	stack_peek(t_stack *stack)
{
	if (!stack->top)
		return (0);
	return (stack->top->value);
}

void	stack_free(t_stack *stack)
{
	t_node	*node;
	t_node	*next;

	node = stack->top;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	free(stack);
}
