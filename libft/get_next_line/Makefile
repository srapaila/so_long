
NAME = gnl.a
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBC = ar rcs

SRCS =  get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

%.o: %.c get_next_line.h
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME) 

re: fclean all