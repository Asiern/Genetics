#Genetics
SRC_s = gengroups_s.c fungg_s.c
SRC_p = gengroups_p.c fungg_p.c
CC = gcc
RM = rm -f
FLAGS = -fopenmp -O2 -Wall -Wextra -Werror

NAME = genetics

all: $(NAME)

$(NAME): $(NAME)
	$(CC) $(FLAGS) -o $(NAME)_s $(SRC_s) -lm
	$(CC) $(FLAGS) -o $(NAME)_p $(SRC_p) -lm

clean:
	$(RM) $(NAME)_p $(NAME)_s

re: clean $(NAME)

.PHONY: all clean re test