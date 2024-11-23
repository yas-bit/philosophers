NAME	= philo
CC		= cc -Wall -Wextra -Werror #-g -fsanitize=address
RM		= rm -f
SRC		= main.c\
		  utils.c\
		  initialize.c\
		  create.c\
		  routine_funcs.c
OBJ		= $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(OBJ) : $(SRC)
	$(CC) -c $(SRC)

clean:
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all