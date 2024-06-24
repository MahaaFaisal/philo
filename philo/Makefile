SRC = main.c assign_values.c create_philos.c routine.c end_program.c time.c monitors.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
THFLAG = -pthread
NAME = philo

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(THFLAG) $(SRC) -o $(NAME) 

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
