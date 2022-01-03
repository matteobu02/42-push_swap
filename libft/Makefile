NAME	=	libft.a

SRCS	=	ft_count_words.c	\
			ft_error.c			\
			ft_free_tab.c		\
			ft_putstr_fd.c		\
			ft_split.c			\
			ft_strcmp.c			\
			ft_strlen.c

OBJS	=	$(SRCS:.c=.o)


# Bonus

SRCS_B	=	gnl/get_next_line.c		\
			gnl/get_next_line_utils.c

OBJS_B	=	$(SRCS_B:.c=.o)

# Bonus end.


CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

AR		=	ar rc


all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

bonus:		$(OBJS) $(OBJS_B)
			$(AR) $(NAME) $(OBJS) $(OBJS_B)
			
clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME) $(OBJS_B)

re:			fclean all

.PHONY:		all clean fclean re
