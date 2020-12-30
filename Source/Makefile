#Source files
SRC_s = gengroups_s.c fungg_s.c
SRC_p = gengroups_p.c fungg_p.c
#Compiler
CC = gcc
RM = rm -f
#Flags
FLAGS = -fopenmp -O2 -Wall -Wextra -Werror

NAME = genetics

all: $(NAME)_p $(NAME)_s 

#Serial
$(NAME)_s : $(NAME)_s
	$(CC) $(FLAGS) -o $(NAME)_s $(SRC_s) -lm
#Parallel	
$(NAME)_p : $(NAME)_p	
	$(CC) $(FLAGS) -o $(NAME)_p $(SRC_p) -lm

clean:
	$(RM) $(NAME)_p $(NAME)_s

re: clean $(NAME)

.PHONY: all clean re