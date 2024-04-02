SRC =	mandatory/large_stack.c mandatory/moves.c mandatory/push_swap.c mandatory/small_stack.c \
		mandatory/sorts_helper.c mandatory/parsing/parsing.c mandatory/parsing/parsing_helper.c

SRCB =  bonus/parsing_bonus/parsing_bonus.c bonus/parsing_bonus/parsing_helper_bonus.c \
		bonus/checker_bonus.c bonus/move_it_bonus.c bonus/moves_bonus.c

OBJ = ${SRC:.c=.o}

OBJB = ${SRCB:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror -I./super_libft

HEADER = mandatory/push_swap.h bonus/checker_bonus.h

NAME = push_swap

NAMEB = checker

LIBFT = super_libft/libft.a

all : $(NAME)

bonus :	${NAMEB}

${NAMEB} : $(OBJB)
	@make -C ./super_libft all
	$(CC) $(CFLAGS) $(OBJB) $(LIBFT) -o $(NAMEB)


$(NAME) : $(OBJ)
	@make -C ./super_libft all
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)


%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@make -C ./super_libft clean
	rm -fr $(OBJ)
	rm -fr $(OBJB)

fclean : clean
	@make -C ./super_libft fclean
	rm -fr push_swap
	rm -fr checker

re : fclean all

.PHONY : bonus all clean fclean