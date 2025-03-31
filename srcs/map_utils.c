/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:15:23 by macaruan          #+#    #+#             */
/*   Updated: 2025/03/31 17:15:04 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*trim_newline(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
	return (str);
}
void	get_map_dimensions(char **map, int *width, int *height)
{
	int	y;
	int	row_len;

	y = 0;
	*width = 0;
	*height = 0;
	while (map[y])
	{
		row_len = ft_strlen(map[y]);
		if (row_len > *width)
			*width = row_len;
		y++;
	}
	*height = y;
}
void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
char	**copy_map(char **map)
{
	int		i;
	char	**map_copy;

	if (!map)
		return (NULL);
	i = 0;
	while (map[i])
		i++;
	map_copy = malloc((i + 1) * sizeof(char *));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			free_map(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}
void	draw_tile(t_game *game, int x, int y, void *texture)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, texture, x
		* game->textures->tile_size, y * game->textures->tile_size);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				draw_tile(game, x, y, game->textures->wall);
			else if (game->map[y][x] == '0')
				draw_tile(game, x, y, game->textures->floor);
			else if (game->map[y][x] == 'P')
				draw_tile(game, x, y, game->textures->player);
			else if (game->map[y][x] == 'C')
				draw_tile(game, x, y, game->textures->collec);
			else if (game->map[y][x] == 'E')
				draw_tile(game, x, y, game->textures->exit);
			x++;
		}
		y++;
	}
}
