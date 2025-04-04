/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:28:35 by srapaila          #+#    #+#             */
/*   Updated: 2025/04/04 18:41:24 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (!check_args(argc, argv[1]))
		return (1);
	if (!parse_map(&game, argv[1]))
		return (1);
	open_game(&game);
	load_images(&game);
	render_map(&game);
	set_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
