/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:24:01 by macaruan          #+#    #+#             */
/*   Updated: 2025/04/01 11:27:59 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_textures(t_game *game)
{
	game->textures->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&game->textures->tile_size, &game->textures->tile_size);
	if (!game->textures->wall)
		handle_error("Error: failed to load wall texture\n", game);
	game->textures->floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &game->textures->tile_size,
			&game->textures->tile_size);
	if (!game->textures->floor)
		handle_error("Error: failed to load floor texture\n", game);
	game->textures->player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &game->textures->tile_size,
			&game->textures->tile_size);
	if (!game->textures->player)
		handle_error("Error: failed to load player texture\n", game);
	game->textures->collec = mlx_xpm_file_to_image(game->mlx,
			"textures/collec.xpm", &game->textures->tile_size,
			&game->textures->tile_size);
	if (!game->textures->collec)
		handle_error("Error: failed to load collectible texture\n", game);
	game->textures->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&game->textures->tile_size, &game->textures->tile_size);
	if (!game->textures->exit)
		handle_error("Error: failed to load exit texture\n", game);
}

void	free_textures(t_game *game)
{
	if (game->textures)
	{
		mlx_destroy_image(game->mlx, game->textures->wall);
		mlx_destroy_image(game->mlx, game->textures->floor);
		mlx_destroy_image(game->mlx, game->textures->player);
		mlx_destroy_image(game->mlx, game->textures->collec);
		mlx_destroy_image(game->mlx, game->textures->exit);
		free(game->textures);
	}
}
