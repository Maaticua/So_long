/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:16:48 by macaruan          #+#    #+#             */
/*   Updated: 2025/03/31 17:17:35 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	floodfill(char **map, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || x >= game->width || y >= game->height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (!is_valid_map_char(map[y][x]) && map[y][x] != 'F')
		handle_error("Error: invalid map character during floodfill\n", game);
	map[y][x] = 'F';
	floodfill(map, x + 1, y, game);
	floodfill(map, x - 1, y, game);
	floodfill(map, x, y + 1, game);
	floodfill(map, x, y - 1, game);
}
int	is_map_solvable(t_game *game)
{
	char	**map_temp;
	int		x;
	int		y;

	map_temp = copy_map(game->map);
	if (!map_temp)
		return (write(2, "Error, map cpy failed\n", 22), 0);
	find_player_loc(game);
	get_map_dimensions(game->map, &game->width, &game->height);
	floodfill(map_temp, game->player_x, game->player_y, game);
	y = -1;
	while (map_temp[++y])
	{
		x = -1;
		while (map_temp[y][++x])
		{
			if (map_temp[y][x] == 'C' || map_temp[y][x] == 'E')
			{
				write(2, "Error: map design is invalid\n", 29);
				return (free_map(map_temp), 0);
			}
		}
	}
	return (free_map(map_temp), 1);
}
