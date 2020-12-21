src = test.c
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror

NAME = test

all: $(NAME)

$(NAME): $(NAME)
	$(CC) $(FLAGS) -o $(NAME) $(src) -lm

clean:
	$(RM) $(NAME)

re: clean $(NAME)

.PHONY: all clean re