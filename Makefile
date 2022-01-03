NAME	=	push_swap

SRCS	=	srcs/main.c			\
			srcs/operations.c	\
			srcs/radix.c		\
			srcs/read_arg.c		\
			srcs/small_sort.c	\
			srcs/utils.c		\
			srcs/utils_1.c

OBJS	=	$(SRCS:.c=.o)


# BONUS

NAME_B	=	checker

SRCS_B	=	bonus/checker_bonus.c		\
			bonus/get_stdin_bonus.c		\
			bonus/operations_bonus.c	\
			bonus/read_arg_bonus.c		\
			bonus/utils_bonus.c

OBJS_B	=	$(SRCS_B:.c=.o)

# Bonus end.

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C libft/
			$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)

bonus:		$(OBJS_B)
			make -C libft/ bonus
			$(CC) $(CFLAGS) $(OBJS_B) -Llibft -lft -o $(NAME_B)

clean:
			rm -rf $(OBJS)
			make -C libft/ clean

fclean:
			rm -rf $(OBJS) $(OBJS_B) $(NAME) $(NAME_B)
			make -C libft/ fclean

re:			fclean $(NAME)

.PHONY:		all clean fclean re
