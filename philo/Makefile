NAME = philo
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
DIR = src
SRC = $(DIR)/actions.c \
      $(DIR)/init.c \
      $(DIR)/main.c \
      $(DIR)/monitoring.c \
      $(DIR)/routine.c \
      $(DIR)/utils.c \
      $(DIR)/validation.c
OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS) Makefile include/philo.h
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re