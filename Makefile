NAME 	=	push_swap
LIBFT	=	libft.a
LIBPATH	=	./libft/
SRCS	= 	stack.c push_swap_rotate.c
OBJS 	=	$(SRCS:%.c=%.o)
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

$(NAME):	$(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBPATH)$(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBPATH) all

all:	$(NAME)

clean:
	rm -f $(OBJS)
	make -C $(LIBPATH) clean

fclean:	clean
	rm -f $(NAME)
	make -C $(LIBPATH) fclean

re: fclean all

.PHONY:	all clean fclean re