/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:24:52 by macaruan          #+#    #+#             */
/*   Updated: 2025/04/01 11:26:43 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	close_game(t_game *game)
{
	free_map(game->map);
	free_textures(game);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
}

int	close_window(t_game *game)
{
	close_game(game);
	return (0);
}

void	free_resources(t_game *game)
{
	if (game->map)
		free_map(game->map);
	if (game->textures)
		free_textures(game);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
		free(game->mlx);
}
