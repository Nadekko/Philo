CC = cc

CFLAGS = -Wall -Werror -Wextra -g3 -pthread 
# -fsanitize=thread
NAME = philo_bonus

SRC = main.c \
	init_struct.c \
	parsing.c \
	philo.c \
	supervisor.c \
	utils.c \
	utils2.c \
	ft_free.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re