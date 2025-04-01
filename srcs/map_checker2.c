/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:25:52 by macaruan          #+#    #+#             */
/*   Updated: 2025/04/01 14:32:58 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	count_map_elements(t_game *game)
{
	int	player;
	int	exit;
	int	collect;

	player = 0;
	exit = 0;
	collect = 0;
	if (!check_map_elements(game, &player, &exit, &collect))
		return (0);
	if (player != 1 || exit != 1 || collect < 1)
		return (write(2, "Error: invalid map setup\n", 25), 0);
	return (1);
}

int	is_map_enclosed(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if ((y == 0 || y == game->height - 1 || x == 0 || x == game->width
					- 1) && game->map[y][x] != '1')
			{
				write(2, "Error: map is not enclosed by walls\n", 36);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	validate_map(t_game *game)
{
	if (!game->map || !game->map[0])
		return (write(2, "Error: map is empty\n", 20), 0);
	if (!check_map_rectangular(game))
		return (0);
	if (!count_map_elements(game))
		return (0);
	if (!is_map_enclosed(game))
			return (0);
	if (!is_map_solvable(game))
		return (0);
	return (1);
}
