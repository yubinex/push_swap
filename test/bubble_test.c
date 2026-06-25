#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	printf("Top -> ");

	while (current)
	{
		printf("%d", current->value);
		if (current->next)
			printf(" -> ");
		current = current->next;
	}

	printf(" <- Bottom\n");
}

int	main(void)
{
	t_state	state;

	state.a = stack_new();
	state.b = stack_new();

	stack_push(state.a, 2);
	stack_push(state.a, 4);
	stack_push(state.a, 1);
	stack_push(state.a, 3);

	printf("Before sorting:\n");
	print_stack(state.a);

	bubble_sort(&state);

	printf("\nAfter sorting:\n");
	print_stack(state.a);

	return (0);
}

//Need to add this to the make file for the test

// TEST_NAME = test_bubble

// TEST_SRCS = test/bubble_test.c 
//             src/stack.c 
//             src/ops_swap.c 
//             src/ops_push.c 
//             src/ops_rotate.c 
//             src/ops_rev_rotate.c 
//             src/parse.c 
//             src/disorder.c 
//             src/sort.c 
//             src/bubble_sort.c

// test_bubble:
// 	$(CC) $(CFLAGS) $(TEST_SRCS) -o $(TEST_NAME)