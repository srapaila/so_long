
NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBC = ar rcs

SRCS =  ft_putchar.c ft_putnbr.c ft_printf.c ft_putstr.c \
		ft_putnbr_unsigned.c ft_putexa.c \
		ft_put_adress.c ft_putptr.c
 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME) 

re: fclean all
