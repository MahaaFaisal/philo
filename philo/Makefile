SRC = debug.c main.c assign_values.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
THFLAG = -lpthread
NAME = philo

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(THFLAG) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
