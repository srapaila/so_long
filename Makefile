NAME = so_long
NAME_BONUS = so_long_bonus

SRC = src/so_long.c src/parse.c src/utils.c src/utils_map.c src/utils_map_check.c src/utils_events.c src/events.c src/images.c 
OBJ = $(SRC:.c=.o)

SRC_BONUS = src/bonus/so_long_bonus.c src/bonus/parse_bonus.c src/bonus/utils_bonus.c src/bonus/utils_map_bonus.c src/bonus/utils_map_check_bonus.c src//bonus/utils_events_bonus.c src/bonus/events_bonus.c src/bonus/images_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

FLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -lmlx -Lminilibx-linux -lXext -lX11 -lm -lz 
RM = rm -rf

LIBFT = libft
LIB = libft/libft.a 
MINILIBX_DIR = ./minilibx-linux

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY) "Compiling $(NAME)" $(NONE)
	@cc $(FLAGS) $(OBJ) $(LIB) $(MLX_FLAGS) -o $(NAME)
	@echo $(GREEN)"$(NAME) compiled"$(NONE)

$(NAME_BONUS): $(OBJ_BONUS)  
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME_BONUS)..." $(NONE)
	@cc $(FLAGS) $(OBJ_BONUS) $(LIB) $(MLX_FLAGS) -o $(NAME_BONUS)
	@echo $(GREEN)"- Compiled -"$(NONE)

$(LIBFT):
	@echo $(CURSIVE)$(GRAY) "Compiling $(LIBFT)"
	@make -s -C libft
	@echo $(GREEN)"$(LIBFT) compiled"

$(MINILIBX_DIR):
	@make -s -C $(MINILIBX_DIR)
	
$(OBJ): %.o: %.c
#	@echo $(CURSIVE)$(GRAY) "Compiling object files" $(NONE)
	@cc $(FLAGS) -c $< -o $@

$(OBJ_BONUS): %.o: %.c
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@cc $(FLAGS) -c $< -o $@

clean:
	@echo $(CURSIVE)$(GRAY) "Removing object files" $(NONE)
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)
	$(RM) $(NAME_BONUS)
	@make -s -C libft clean

fclean: clean
	@echo $(CURSIVE)$(GRAY) "Removing $(NAME)" $(NONE)
	$(RM) $(NAME)
	$(RM) $(OBJ_BONUS)
	$(RM) $(NAME_BONUS)
	@make -s -C libft fclean

re: fclean all

bonus: $(LIBFT) $(NAME_BONUS)

.PHONY: all clean fclean re $(LIBFT)