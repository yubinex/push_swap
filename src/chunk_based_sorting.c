#include "../push_swap.h"

int ft_sqrt(int n) //Returns the integer square root of n(It finds the largest integer i)
{
    int i;

    i = 1;
    while (i * i <= n)
        i++;
    return (i - 1);
}

int chunk_count(int size) //This is the same as ft_sqrt
{
   return (ft_sqrt(size));
}

int has_index_range(t_stack *stack, int start, int end) //checks whether stack A has at least one node with an index that belongs to a chunk
{
    t_node *tmp;

    tmp = stack->top;
    while (tmp)
    {
        if (tmp->index >= start && tmp->index <= end)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

int max_pos(t_stack *stack) //returns largest index in a stack
{
    t_node  *tmp;
    int     max;
    int     pos;
    int     i;

    tmp = stack->top;
    max = tmp->index;
    pos = 0;
    i = 0;

    while (tmp)
    {
        if (tmp->index > max)
        {
            max = tmp->index;
            pos = i;
        }
        tmp = tmp->next;
        i++;
    }
    return (pos);
}

void push_chunks(t_state *state)
{
    int chunks;
    int chunk_size;
    int chunk;
    int start;
    int end;
    int size;

    size = state->a->size; //Compute chunk information
    chunks = ft_sqrt(size);
    chunk_size = size / chunks;

    chunk = 0;
    while (chunk < chunks)
    {
        start = chunk * chunk_size; //Compute boundaries

        if (chunk == chunks - 1) //Last chunk special case (without it leftover form division would be lost)
            end = size - 1;
        else
            end = (chunk + 1) * chunk_size - 1;

        while (has_index_range(state->a, start, end))
        {
            if (state->a->top->index >= start
                && state->a->top->index <= end) //Top belongs to the chunk
            {
                op_pb(state);
                if (state->b->top->index < (start + end) / 2) //Keep smaller values deeper in B
                    op_rb(state);
            }
            else
                op_ra(state); //Top doesn't belong to this chunk
        }
        chunk++;
    }
}
