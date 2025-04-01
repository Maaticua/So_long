/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:34:57 by macaruan          #+#    #+#             */
/*   Updated: 2025/04/01 11:27:06 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	find_player_loc(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	handle_error("Error: player not found on the map\n", game);
}

void	count_collec(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->total_collec = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->total_collec++;
			x++;
		}
		y++;
	}
}

void	handle_error(const char *message, t_game *game)
{
	if (message)
		write(2, message, ft_strlen(message));
	if (game)
		close_game(game);
	exit(1);
}

void	init_textures_struct(t_game *game)
{
	game->textures = malloc(sizeof(t_textures));
	if (!game->textures)
		handle_error("Error: failed to allocate textures\n", game);
	game->textures->tile_size = 64;
}

void	init_game(t_game *game, const char *map_path)
{
	game->map = read_map(map_path);
	if (!game->map)
		handle_error("Error: invalid map\n", game);
	if (!validate_map(game))
		handle_error("Error: map validation failed\n", game);
	find_player_loc(game);
	count_collec(game);
	game->collected = 0;
	game->move_count = 0;
	get_map_dimensions(game->map, &game->width, &game->height);
	init_textures_struct(game);
}
