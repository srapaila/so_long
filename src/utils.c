/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:57:51 by srapaila          #+#    #+#             */
/*   Updated: 2025/04/01 19:59:10 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int is_valid(char c)
{
    return(c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C' || c == 'A');
}


int check_args(int argc, char *argv)
{
    int len;

    if(argc != 2)
        return(write(2, "Error: Wrong args\n", 6), 0);
    len = ft_strlen(argv);
    if(len < 4 || ft_strncmp(argv + len - 4, ".ber", 4) != 0)
        return(write(2, "Error: Not .ber\n", 16), 0);
    return(1);
}   

int open_game(t_game *game)
{
    game->mlx = mlx_init();
    if(!game->mlx)
        return(write(2, "Error MLX\n", 10), 1);
    game->win = mlx_new_window(game->mlx, game->map_width * TILE_SIZE, game->map_height * TILE_SIZE, "so_long");
    if(!game->win)
        return(write(2, "Error MLX\n", 10), 1);
    return (0);
}

void clean_gnl(int fd)
{
    char *line;
    
    while ((line = get_next_line(fd)) != NULL)
        free(line);
}