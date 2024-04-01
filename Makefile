SRC =	mandatory/large_stack.c mandatory/moves.c mandatory/push_swap.c mandatory/small_stack.c \
		mandatory/sorts_helper.c mandatory/parsing/parsing.c mandatory/parsing/parsing_helper.c 

SRCB = bonus/parsing/parsing.c bonus/parsing/parsing_helper.c bonus/checker.c bonus/move_it.c bonus/moves.c

CC = cc

CFLAGS = -Wall -Wextra -Werror -I./super_libft

HEADER = mandatory/push_swap.h
HEADERB = bonus/checker.h

NAME = push_swap
NAMEB = checker

LIBFT = super_libft/libft.a

all : $(NAME)

$(NAME) : $(SRC) $(HEADER)
	make -C ./super_libft all
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME) -fsanitize=address -g

bonus : $(SRC) $(HEADERB)
	make -C ./super_libft all
	$(CC) $(CFLAGS) $(SRCB) $(LIBFT) -o $(NAMEB) -fsanitize=address -g

clean : 
	make -C ./super_libft clean

fclean :
	make -C ./super_libft fclean
	rm -fr push_swap
	rm -fr checker

.PHONY : bonus