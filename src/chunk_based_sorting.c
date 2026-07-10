#include "../push_swap.h"

void push_chunks(t_state *state)
{
    int chunks;
    int chunk_size;
    int chunk;
    int start;
    int end;
    int size;
    int pos;

    size = state->a->size; //Compute chunk information
    assign_indices(state->a);  
    chunks = ft_sqrt(size);
    if (chunks == 0)
        chunks = 1;
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
            pos = find_chunk_pos(state->a, start, end);
            if (pos <= state->a->size / 2)
            {
                while (pos--)
                    op_ra(state);
            }
            else
            {
                pos = state->a->size - pos;
                while (pos--)
                    op_rra(state);
            }
            op_pb(state);

            if (state->b->top->index < (start + end) / 2)
                op_rb(state);
        }
        chunk++;
    }
}

void push_back_sorted(t_state *state)
{
    int pos;

    while (state->b->size)
    {
        pos = max_pos(state->b);

        if (pos <= state->b->size / 2)
            while (pos--)
                op_rb(state);
        else
        {
            pos = state->b->size - pos;
            while (pos--)
                op_rrb(state);
        }
        op_pa(state);
    }
}
