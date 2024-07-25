NAME 	=	push_swap
LIBFT	=	libft/libft.a
LIBPATH	=	./libft/
SRC_DIR	=	./src/
SRCS	=	$(wildcard $(SRC_DIR)*.c)
OBJS 	=	$(SRCS:%.c=%.o)
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

all:	$(NAME)

$(LIBFT):
	make -C $(LIBPATH)

$(NAME):	$(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(IFLAFS) -o $(NAME) $(OBJS) $(LIBFT)

clean:
	rm -f $(OBJS)
	make -C $(LIBPATH) clean

fclean:	clean
	rm -f $(NAME)
	make -C $(LIBPATH) fclean

re: fclean all

.PHONY:	all clean fclean re
