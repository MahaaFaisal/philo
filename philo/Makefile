SRC = main.c assign_values.c create_threads.c routine.c join_threads.c time.c
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
