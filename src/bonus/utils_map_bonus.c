/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:03:34 by srapaila          #+#    #+#             */
/*   Updated: 2025/04/04 18:51:57 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	trim_newline(char *line)
{
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
}

int	validate_line(char *line, t_game *game, int y)
{
	int	x;

	x = 0;
	while (x < game->map_width)
	{
		game->map[y][x] = line[x];
		if (!is_valid(line[x]))
			return (0);
		x++;
	}
	game->map[y][game->map_width] = '\0';
	return (1);
}

void	count_map_elements(t_game *game, int y, int *player, int *exit)
{
	int	x;

	x = -1;
	while (++x < game->map_width)
	{
		if (game->map[y][x] == 'P')
		{
			(*player)++;
			game->player_pos.x = x;
			game->player_pos.y = y;
		}
		if (game->map[y][x] == 'E')
		{
			(*exit)++;
			game->exit_pos.y = y;
			game->exit_pos.x = x;
		}
	}
}

int	check_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_width)
	{
		if (game->map[0][x] != '1')
			return (write(2, "Error: NoWalls\n", 15), 0);
		if (game->map[game->map_height - 1][x] != '1')
			return (write(2, "Error: NoWalls\n", 15), 0);
		x++;
	}
	y = 0;
	while (y < game->map_height)
	{
		if (game->map[y][0] != '1')
			return (write(2, "Error: NoWalls\n", 15), 0);
		if (game->map[y][game->map_width - 1] != '1')
			return (write(2, "Error: NoWalls\n", 15), 0);
		y++;
	}
	return (1);
}

void	count_collectible(t_game *game, int y, int *c)
{
	int	x;

	x = -1;
	while (++x < game->map_width)
	{
		if (game->map[y][x] == 'C')
			(*c)++;
	}
}
