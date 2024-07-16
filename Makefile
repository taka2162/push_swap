NAME 	=	push_swap
LIBFT	=	libft.a
LIBPATH	=	./libft/
SRCS	= 	main.c error_handling.c input_argvs.c stack.c swap_and_push.c rotate_and_reverse.c get_value.c quick_sort.c extreme_sort.c insertion_sort.c calculate_best_node.c direction.c
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