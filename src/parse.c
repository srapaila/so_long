/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:25:32 by srapaila          #+#    #+#             */
/*   Updated: 2025/04/04 17:30:53 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	allocate_map(t_game *game)
{
	int	i;

	game->map = (char **)malloc(sizeof(char *) *(game->map_height));
	if (!game->map)
		return (0);
	i = 0;
	while (i < (game->map_height))
	{
		game->map[i] = (char *)malloc(sizeof(char) * (game->map_width + 1));
		if (!game->map[i])
		{
			while (i-- > 0)
				free(game->map[i]);
			return (free(game->map), 0);
		}
		game->map[i][game->map_width] = '\0';
		i++;
	}
	return (1);
}

int	calculate_map_size(t_game *game, int fd)
{
	char	*line;
	size_t	width;
	size_t	height;

	width = 0;
	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		trim_newline(line);
		if (width == 0)
			width = ft_strlen(line);
		else if (ft_strlen(line) != width)
			return (write(2, "Error: wrong size\n", 6), free(line), 0);
		free(line);
		height++;
		line = get_next_line(fd);
	}
	game->map_width = width;
	game->map_height = height;
	return (1);
}

int	read_and_validate(t_game *game, int fd)
{
	char	*line;
	int		y;

	if (!game->map)
		return (0);
	y = 0;
	line = get_next_line(fd);
	while (y < game->map_height && line != NULL)
	{
		trim_newline(line);
		if (!validate_line(line, game, y))
			return (free(line), write(2, "Error: invalid line\n", 6), 0);
		free(line);
		y++;
		line = get_next_line(fd);
	}
	if (!check_walls(game))
		return (0);
	if (y != game->map_height)
		return (write(2, "Error\n", 6), 0);
	return (1);
}

int	validate_map_contents(t_game *game)
{
	int	player;
	int	exit;
	int	c;
	int	y;

	c = 0;
	player = 0;
	exit = 0;
	y = -1;
	while (++y < game->map_height)
		count_map_elements(game, y, &player, &exit);
	y = -1;
	while (++y < game->map_height)
		count_collectible(game, y, &c);
	if (player != 1 || exit != 1 || c < 1)
		return (write(2, "Error\n", 6), 0);
	game->collectibles = c;
	return (1);
}

int	parse_map(t_game *game, const char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (write(2, "Error\n", 6), 0);
	if (!calculate_map_size(game, fd))
	{
		clean_gnl(fd);
		close(fd);
		return (0);
	}
	close(fd);
	if (!allocate_map(game))
		return (0);
	fd = open(map_file, O_RDONLY);
	if (!read_and_validate(game, fd))
		return (free_map(game), clean_gnl(fd), close(fd), 0);
	close(fd);
	if (!validate_map_contents(game) || \
		!map_is_playable(game))
		return (free_map(game), 0);
	return (1);
}
