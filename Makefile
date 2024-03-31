SRC =	mandatory/large_stack.c mandatory/moves.c mandatory/push_swap.c mandatory/small_stack.c \
		mandatory/sorts_helper.c mandatory/parsing/parsing.c mandatory/parsing/parsing_helper.c 

CC = cc

CFLAGS = -Wall -Wextra -Werror -I./super_libft

HEADER = mandatory/push_swap.h

NAME = push_swap

LIBFT = super_libft/libft.a

all : $(NAME)

$(NAME) : $(SRC) $(HEADER)
	make -C ./super_libft all
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)

clean : 
	make -C ./super_libft clean

fclean :
	make -C ./super_libft fclean
	rm -fr push_swap