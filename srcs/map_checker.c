/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:17:22 by macaruan          #+#    #+#             */
/*   Updated: 2025/03/31 17:17:04 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E');
}
int	check_map_type(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
	{
		write(2, "Error wrong map type\n", 22);
		return (0);
	}
	return (1);
}
int	check_map_rectangular(t_game *game)
{
	int	y;
	int	width;

	y = 0;
	width = ft_strlen(game->map[0]);
	while (game->map[y])
	{
		if ((int)ft_strlen(game->map[y]) != width)
		{
			write(2, "Error: map is not rectangular\n", 30);
			return (0);
		}
		y++;
	}
	return (1);
}
int	count_map_elements(t_game *game)
{
	int	x;
	int	y;
	int	player;
	int	exit;
	int	collect;

	y = 0;
	player = 0;
	exit = 0;
	collect = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (!is_valid_map_char(game->map[y][x]))
				return (write(2, "Error: invalid character\n", 26), 0);
			if (game->map[y][x] == 'P')
				player++;
			if (game->map[y][x] == 'E')
				exit++;
			if (game->map[y][x] == 'C')
				collect++;
			x++;
		}
		y++;
	}
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
	if (!is_map_enclosed(game))
		return (0);
	if (!count_map_elements(game))
		return (0);
	if (!is_map_solvable(game))
		return (0);
	return (1);
}
