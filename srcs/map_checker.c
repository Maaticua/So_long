/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:17:22 by macaruan          #+#    #+#             */
/*   Updated: 2025/04/01 11:27:33 by macaruan         ###   ########.fr       */
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

int	is_valid_element(char c, int *player, int *exit, int *collect)
{
	if (!is_valid_map_char(c))
		return (write(2, "Error: invalid character\n", 26), 0);
	if (c == 'P')
		(*player)++;
	if (c == 'E')
		(*exit)++;
	if (c == 'C')
		(*collect)++;
	return (1);
}

int	check_map_elements(t_game *game, int *player, int *exit, int *collect)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (!is_valid_element(game->map[y][x], player, exit, collect))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
