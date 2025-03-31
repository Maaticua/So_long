/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:30:45 by macaruan          #+#    #+#             */
/*   Updated: 2025/03/31 14:45:09 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	t_game	game;
	int		window_width;
	int		window_height;

	if (ac != 2)
	{
		write(2, "Error: incorrect arguments\n", 27);
		return (1);
	}
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	init_game(&game, av[1]);
	window_width = game.width * game.textures->tile_size;
	window_height = game.height * game.textures->tile_size;
	game.mlx_win = mlx_new_window(game.mlx, window_width, window_height, "so_long");
	init_textures(&game);
	draw_map(&game);
	mlx_key_hook(game.mlx_win, handle_keys, &game);
	mlx_hook(game.mlx_win, 17, 0, close_wind, &game);
	mlx_loop(game.mlx);
	return (0);
}
