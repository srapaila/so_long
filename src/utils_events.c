/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:54:52 by srapaila          #+#    #+#             */
/*   Updated: 2025/04/04 17:36:49 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_game(t_game *game)
{
	free_map(game);
	if (game->mlx)
	{
		if (game->wall.img)
			mlx_destroy_image(game->mlx, game->wall.img);
		if (game->floor.img)
			mlx_destroy_image(game->mlx, game->floor.img);
		if (game->player.img)
			mlx_destroy_image(game->mlx, game->player.img);
		if (game->collectible.img)
			mlx_destroy_image(game->mlx, game->collectible.img);
		if (game->exit.img)
			mlx_destroy_image(game->mlx, game->exit.img);
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

int	handle_close(t_game *game)
{
	close_game(game);
	return (0);
}

void	free_map(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		if (game->map[y])
			free(game->map[y]);
		y++;
	}
	free(game->map);
	game->map = NULL;
	if (game->map_copy)
	{
		y = 0;
		while (y < game->map_height)
		{
			if (game->map_copy[y])
				free(game->map_copy[y]);
			y++;
		}
		free(game->map_copy);
		game->map_copy = NULL;
	}
}

void	handle_collect(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
	{
		game->collected++;
		game->map[new_y][new_x] = '0';
	}
}

void	handle_exit(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collected == game->collectibles)
		{
			ft_printf("You won, Total moves: %d\n", game->moves);
			close_game(game);
		}
		else
		{
			ft_printf("Exit is blocked. Collect all items first\n");
			return ;
		}
	}
}
