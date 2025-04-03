/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_check_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:52:16 by srapaila          #+#    #+#             */
/*   Updated: 2025/04/03 16:45:05 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int map_is_playable(t_game *game)
{
    if(!create_map_copy(game))
        return(write(2, "Error\n", 6), 0);
    if(!check_map_is_playable(game))
        return(write(2, "Error: Not playable\n", 20), 0);
    return(1);
}

int create_map_copy(t_game *game)
{
    int y;

    game->map_copy = (char **)malloc(sizeof(char *) * game->map_height);
    if(!game->map_copy)   
        return(0);
    y = 0;
    while(y < game->map_height)
    {
        game->map_copy[y] = ft_strdup(game->map[y]);
        if(!game->map_copy)
            return (0);
        y++;
    }
    return (1);
}

int check_map_is_playable(t_game *game)
{
    int x;
    int y;

    y = 0;
    while(y < game->map_height)
    {
        x = 0;
        while(x < game->map_width)
        {
            if(game->map_copy[y][x] == 'P')
                check_from_player(game, y, x);
            x++;
        }
        y++;
    }
    return(game->exit_found && game->r_collected == game->collectibles);
}

int check_from_player(t_game *game, int y, int x)
{
    if (y <  0 || y >= game->map_height || x < 0 || x >= game->map_width)
        return (0);
    if (game->map_copy[y][x] == '1' || game->map_copy[y][x] == 'V')
        return (0);
    if(game->map_copy[y][x] == 'F')
        return (0);
    if(game->map_copy[y][x] == 'E')
    {
        game->map_copy[y][x] = 'V';
        game->exit_found = 1;
        return(1); 
    }    
    if (game->map_copy[y][x] == 'C')
        game->r_collected++;
    game->map_copy[y][x] = 'V';
    check_from_player(game, y, x + 1);
    check_from_player(game, y + 1, x);
    check_from_player(game, y - 1, x);
    check_from_player(game, y, x - 1);
    return(game->exit_found && game->r_collected == game->collectibles);
}
