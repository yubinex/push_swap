#include "../push_swap.h"

// static int	stack_size(t_stack *a)
// {
// 	int	size;

// 	size = 0;
// 	while (a)
// 	{
// 		size++;
// 		a = a->next;
// 	}
// 	return (size);
// }

static int stack_size(t_stack *a)
{
    int     size;
    t_node  *current;
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
	int	size;
	int	i;
	int	j;
	t_node  *current;

	size = stack_size(state->a);
	i = 0;
	while (i < size - 1)
	{
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
		i++;
	}
}
