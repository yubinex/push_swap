NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

SRCS = src/push_swap.c \
       src/stack.c \
       src/ops_swap.c \
       src/ops_push.c \
       src/ops_rotate.c \
       src/ops_rev_rotate.c \
       src/parse.c \
       src/disorder.c \
       src/sort.c \
       src/complex_sort.c \
       src/bench.c \
       src/chunk_based_sorting.c \
       src/chunk_based_helpers.c \
       src/indices.c \
       src/sort_tiny.c

OBJ_DIR = obj
OBJS    = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
