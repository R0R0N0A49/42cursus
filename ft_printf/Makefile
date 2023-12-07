NAME=libftprintf.a
SRCS=ft_printf.c ft_putstr_fd.c ft_putchar_fd.c ft_putnbr_fd.c ft_strlen.c ft_printf_utils.c
OBJS= $(SRCS:.c=.o)
RM=rm -f
CC=gcc
CFLAGS=-Wextra -Werror -Wall -g
ARRC=ar -rc

all:$(NAME)

$(NAME): $(OBJS)
	$(ARRC) $(NAME) $(OBJS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)
