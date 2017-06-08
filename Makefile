CC = gcc

ifeq ($(DEBUG),yes)
    CFLAGS = -Wall -Wextra -O0 -g
else
    CFLAGS = -Wall -Wextra -O2
endif

NAME = push_swap

SRC_UTIL = my_malloc.c ft.c circular_linked_list.c circular_linked_list_op.c
SRC_TEST = test_circular_linked_list.c test_op.c test_two_stacks.c

SRC = $(SRC_UTIL) $(SRC_TEST) two_stacks.c two_stacks_do_op.c \
		two_stacks_op_s.c two_stacks_op_p.c two_stacks_op_r.c two_stacks_op_rr.c \
		algo.c algo2.c main.c
OBJ = $(SRC:.c=.o)

VPATH = test util src
IFLAGS = -Itest -Iutil -Isrc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ $(IFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
