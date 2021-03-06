NAME = philo

FLAGS = -Wall -Wextra -Werror

CC = gcc #-g3 -fsanitize=address

HEADER = include/philosophers.h

SRCS =  src/main.c \
		src/ft_utils.c \
		src/parsing.c \
		src/philosophers.c \
		src/ft_philo.c \
		src/ft_exit.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(HEADER)
		gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADER)
		$(CC) $(OBJS) -I $(HEADER) $(FLAGS) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: fclean re all clean