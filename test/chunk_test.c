#include "push_swap.h"
#include <stdio.h>

t_node *new_node(int value)
{
    t_node *node;

    node = malloc(sizeof(t_node));
    if (!node)
        return (NULL);

    node->value = value;
    node->index = -1;
    node->next = NULL;
    node->prev = NULL;

    return (node);
}

void push_back(t_stack *stack, int value)
{
    t_node *new;
    t_node *tmp;

    new = new_node(value);
    if (!new)
        return;

    new->next = NULL;

    if (!stack->top)
    {
        new->prev = NULL;
        stack->top = new;
        stack->bottom = new;
    }
    else
    {
        tmp = stack->bottom;

        tmp->next = new;
        new->prev = tmp;

        stack->bottom = new;
    }

    stack->size++;
}

void print_stack(t_stack *stack)
{
    t_node *tmp;

    tmp = stack->top;
    printf("Value\tIndex\n");
    printf("-----------------\n");
    while (tmp)
    {
        printf("%d\t%d\n", tmp->value, tmp->index);
        tmp = tmp->next;
    }
}

void free_stack(t_stack *stack)
{
    t_node *tmp;

    while (stack->top)
    {
        tmp = stack->top;
        stack->top = stack->top->next;
        free(tmp);
    }
}

t_stack *init_stack(void)
{
    t_stack *stack;

    stack = malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);

    stack->top = NULL;
    stack->size = 0;

    return (stack);
}

int main(void)
{
    t_state state;

    state.a = init_stack();
    state.b = init_stack();

    push_back(state.a, 42);
    push_back(state.a, 5);
    push_back(state.a, 100);
    push_back(state.a, -3);
    push_back(state.a, 17);
    push_back(state.a, 4);
    push_back(state.a, 55);
    push_back(state.a, 57);
    push_back(state.a, 97);
    push_back(state.a, 14);
    push_back(state.a, 21);
    push_back(state.a, 31);
    push_back(state.a, 66);
    push_back(state.a, 81);
    push_back(state.a, 88);

    assign_indices(state.a);

    printf("Before push_chunks:\n");
    print_stack(state.a);
    printf("\n");

    push_chunks(&state);
    push_back_sorted(&state);

    printf("\nStack A:\n");
    print_stack(state.a);

    printf("\nStack B:\n");
    print_stack(state.b);

    return (0);
}

// TEST_NAME = test_chunks

// TEST_SRCS = test/chunk_test.c \
//             src/stack.c \
//             src/ops_swap.c \
//             src/ops_push.c \
//             src/ops_rotate.c \
//             src/ops_rev_rotate.c \
//             src/parse.c \
//             src/disorder.c \
//             src/sort.c \
//             src/complex_sort.c \
//             src/bench.c \
//             src/chunk_based_sorting.c \
//             src/chunk_based_helpers.c \
//             src/indices.c

// test_chunks:
// 	$(CC) $(CFLAGS) $(TEST_SRCS) -o $(TEST_NAME)