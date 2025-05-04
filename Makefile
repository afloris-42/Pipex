NAME = pipex

LIBFT_DIR = libft
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LIBFT = $(LIBFT_DIR)/libft.a 


SRCS = src/child_and_parent.c src/find_and_execute.c src/pipex.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c include/pipex.h include/ft_printf.h include/libft.h
	$(CC) $(CFLAGS) -I include -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re