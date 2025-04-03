/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:33:29 by srapaila          #+#    #+#             */
/*   Updated: 2025/04/02 18:22:41 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line/get_next_line.h"
# include "../libft/ft_printf/ft_printf.h"
# include <X11/keysym.h>

#ifndef TILE_SIZE
# define TILE_SIZE 64
#endif

typedef struct s_map
{
    int x;
    int y;
}   t_map;

typedef struct	s_img {
	void	*img;
}				t_img;

typedef struct s_game {
    void    *mlx;
    void    *win;
    char    *map_path;
    char    **map;
    char    **map_copy;
    int     map_width;
    int     map_height;
    int     collectibles;
    int     r_collected;
    int     collected;
    int     exit_found;
    int     moves;
    int     status;
    t_map   player_pos;
    t_map   exit_pos;
    t_img   wall;
    t_img   floor;
    t_img   player;
    t_img   collectible;
    t_img    exit;
}               t_game;


//utils
int check_args(int argc, char *argv);
int is_valid(char c);
int open_game(t_game *game);
void clean_gnl(int fd);

//utils_map
void    trim_newline(char *line);
int validate_line(char *line , t_game *game, int y);
void count_map_elements(t_game *game, int y, int *player, int *exit, int *c);
int check_walls(t_game *game);

//parse
int allocate_map(t_game *game);
int calculate_map_size(t_game *game, int fd);
int read_and_validate(t_game *game, int fd);
int validate_map_contents(t_game *game);
int parse_map(t_game *game, const char *map_file);

//utils_map_check
int map_is_playable(t_game *game);
int create_map_copy(t_game *game);
int check_map_is_playable(t_game *game);
int check_from_player(t_game *game, int x, int y);

//events
void set_hooks(t_game *game);
void move_player(t_game *game, int dx, int dy);
int handle_keypress(int keycode, t_game *game);


//images
void load_images(t_game *game);
void render_map(t_game *game);

//utils events
int handle_close(t_game *game);
void free_map(t_game *game);
void close_game(t_game *game);
void handle_collect(t_game *game, int new_x, int new_y);
void handle_exit(t_game *game, int new_x, int new_y);

#endif