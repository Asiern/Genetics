#Genetics
SRC = gengroups_s.c fungg_s.c
CC = gcc
RM = rm -f
FLAGS = -fopenmp -O2 #-Wall -Wextra -Werror

NAME = genetics

all: $(NAME)

$(NAME): $(NAME)
	$(CC) $(FLAGS) -o $(NAME) $(SRC) -lm

clean:
	$(RM) $(NAME)

re: clean $(NAME)

.PHONY: all clean re test