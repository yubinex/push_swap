/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indices.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaur <jubaur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 09:09:40 by jubaur            #+#    #+#             */
/*   Updated: 2026/07/14 09:13:04 by jubaur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*copy_values(t_stack *stack)
{
	int		*arr;
	t_node	*tmp;
	int		i;

	arr = malloc(sizeof(int) * stack->size);
	if (!arr)
		return (NULL);
	tmp = stack->top;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	return (arr);
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	assign_indices(t_stack *stack)
{
	int		*arr;
	t_node	*tmp;
	int		i;

	arr = copy_values(stack);
	if (!arr)
		return ;
	sort_array(arr, stack->size);
	tmp = stack->top;
	while (tmp)
	{
		i = 0;
		while (i < stack->size)
		{
			if (arr[i] == tmp->value)
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(arr);
}
