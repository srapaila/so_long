/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:06:57 by srapaila          #+#    #+#             */
/*   Updated: 2025/04/02 15:45:28 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void set_hooks(t_game *game)
{
    mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
    mlx_hook(game->win, 17, 1L << 0, handle_close, game);
}


int handle_keypress(int keycode, t_game *game)
{
    if(keycode == XK_Escape)
        close_game(game);
    else if(keycode == XK_w || keycode == 65362)
        move_player(game, 0, -1);
    else if(keycode == XK_s || keycode == 65364)
        move_player(game, 0, 1);
    else if(keycode == XK_a || keycode == 65361)
        move_player(game, -1, 0);
    else if(keycode == XK_d || keycode == 65363)
        move_player(game, 1, 0);
    return(0);
}

void move_player(t_game *game, int dx, int dy)
{
    int new_x;
    int new_y;

    new_x = game->player_pos.x + dx;
    new_y = game->player_pos.y + dy;
    if(new_x >= 0 && new_x < game->map_width &&
        new_y >= 0 && new_y < game->map_height && 
        game->map[new_y][new_x] != '1' &&
        game->map[new_y][new_x] != 'E')
    {
        handle_collect(game, new_x, new_y);
        game->map[game->player_pos.y][game->player_pos.x] = '0';
        game->player_pos.x = new_x;
        game->player_pos.y = new_y;
        game->map[game->player_pos.y][game->player_pos.x] = 'P';          
        game->moves++;
        ft_printf("Moves: %d\n", game->moves);
        render_map(game);
    }
    else if( game->map[new_y][new_x] == 'E')
        handle_exit(game, new_x, new_y);
}

