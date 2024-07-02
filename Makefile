NAME 	=	push_swap
LIBFT	=	libft.a
LIBPATH	=	./libft/
SRCS	= 	stack.c swap_and_push.c rotate_and_reverse.c sort_three_nodes.c input_argvs.c compression.c quick_sort.c extreme_sort.c direction.c
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