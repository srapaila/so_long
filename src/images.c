/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:38:05 by srapaila          #+#    #+#             */
/*   Updated: 2025/04/04 17:26:34 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int	width;
	int	height;

	game->wall.img = mlx_xpm_file_to_image(game->mlx,
			"images/wall.xpm", &width, &height);
	game->floor.img = mlx_xpm_file_to_image(game->mlx,
			"images/floor.xpm", &width, &height);
	game->player.img = mlx_xpm_file_to_image(game->mlx,
			"images/player.xpm", &width, &height);
	game->collectible.img = mlx_xpm_file_to_image(game->mlx,
			"images/collectible.xpm", &width, &height);
	game->exit.img = mlx_xpm_file_to_image(game->mlx,
			"images/exit.xpm", &width, &height);
	if (!game->floor.img || !game->wall.img || !game->player.img || \
			!game->collectible.img || !game->exit.img)
		return ;
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map_height)
	{
		x = -1;
		while (++x < game->map_width)
		{
			{
				if (game->map[y][x] == '1')
					put_image(game, game->map[y][x], y, x);
				else if (game->map[y][x] == '0')
					put_image(game, game->map[y][x], y, x);
				else if (game->map[y][x] == 'P')
					put_image(game, game->map[y][x], y, x);
				else if (game->map[y][x] == 'C')
					put_image(game, game->map[y][x], y, x);
				else if (game->map[y][x] == 'E')
					put_image(game, game->map[y][x], y, x);
			}
		}
	}
}

void	put_image(t_game *game, char img, int y, int x)
{
	if (img == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall.img, x * TILE_SIZE, y * TILE_SIZE);
	else if (img == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->floor.img, x * TILE_SIZE, y * TILE_SIZE);
	else if (img == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.img, x * TILE_SIZE, y * TILE_SIZE);
	else if (img == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collectible.img, x * TILE_SIZE, y * TILE_SIZE);
	else if (img == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit.img, x * TILE_SIZE, y * TILE_SIZE);
}
