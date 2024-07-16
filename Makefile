NAME 	=	push_swap
LIBFT	=	libft/libft.a
LIBPATH	=	./libft/
SRCS	= 	main.c error_handling.c input_argvs.c stack.c swap_and_push.c rotate_and_reverse.c get_value.c quick_sort.c extreme_sort.c insertion_sort.c calculate_best_node.c direction.c
OBJS 	=	$(SRCS:%.c=%.o)
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

all:	$(NAME)

$(LIBFT):
	make -C $(LIBPATH)

$(NAME):	$(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

clean:
	rm -f $(OBJS)
	make -C $(LIBPATH) clean

fclean:	clean
	rm -f $(NAME)
	make -C $(LIBPATH) fclean

re: fclean all

.PHONY:	all clean fclean re