CC = gcc

ifeq ($(DEBUG),yes)
    CFLAGS = -Wall -Wextra -O0 -g
else
    CFLAGS = -Wall -Wextra -O2
endif

NAME = push_swap
NAME_CHECKER = checker

SRC_UTIL = my_malloc.c ft.c circular_linked_list.c circular_linked_list_op.c \
			slist.c get_next_byte.c
SRC_STACKS = two_stacks.c two_stacks_do_op.c \
        two_stacks_op_s.c two_stacks_op_p.c \
		two_stacks_op_r.c two_stacks_op_rr.c \
		print_solution.c

SRC = $(SRC_UTIL) $(SRC_TEST) $(SRC_STACKS) algo.c algo2.c bruteforce.c main.c
SRC_CHECKER = $(SRC_UTIL) $(SRC_TEST) $(SRC_STACKS) get_next_op.c checker.c
OBJ = $(SRC:.c=.o)
OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

VPATH = test util src
IFLAGS = -Itest -Iutil -Isrc

all: $(NAME) $(NAME_CHECKER)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(NAME_CHECKER): $(OBJ_CHECKER)
	$(CC) $(CFLAGS) -o $(NAME_CHECKER) $(OBJ_CHECKER)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ $(IFLAGS)

clean:
	rm -f $(OBJ) $(OBJ_CHECKER)

fclean: clean
	rm -f $(NAME) $(NAME_CHECKER)

re: fclean all

.PHONY: all clean fclean re
