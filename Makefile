NAME = pipex

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror


SRCS = src/child_and_parent.c src/find_and_execute.c src/pipex.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c include/pipex.h include/ft_printf.h include/libft.h
	$(CC) $(CFLAGS) -I include -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re