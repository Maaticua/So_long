/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:30:45 by macaruan          #+#    #+#             */
/*   Updated: 2025/03/24 17:17:04 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	close_wind(t_game *game)
{
	if (game->mlx_win)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		game->mlx_win = NULL;
	}

	if (game->mlx)
	{
		free(game->mlx);
		game->mlx = NULL;
	}
	free(game);
	exit(0);
	return (0);
}
int	handle_keys(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		close_wind(game);
	return (0);
}
int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
	{
		write(2, "ag pa b1", 8);
		return (1);
	}

	game = malloc(sizeof(t_game));
	if (!game)
	{
		write(2, "Error\n", 6);
		return (1);
	}

	game->textures = malloc(sizeof(t_textures));
	if (!game->textures)
	{
    	free(game);
		write(2, "Error\n", 6);
		return (1);
	}

	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free(game);
		write(2, "Error\n", 6);
		return (1);
	}

	game->mlx_win = mlx_new_window(game->mlx, 1920, 1080, "so_long");
	if (!game->mlx_win)
	{
		free(game->mlx);
		free(game);
		write(2, "Error\n", 6);
		return (1);
	}

	game->map = read_map(av[1]);
	if (!game->map)
	{
		write(2, "Error: invalid map\n", 19);
		return (1);
	}
	
	game->textures->tile_size = 64;
	game->textures->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &game->textures->tile_size, &game->textures->tile_size);
	game->textures->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &game->textures->tile_size, &game->textures->tile_size);
	game->textures->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &game->textures->tile_size, &game->textures->tile_size);
	game->textures->collec = mlx_xpm_file_to_image(game->mlx, "textures/collec.xpm", &game->textures->tile_size, &game->textures->tile_size);
	game->textures->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &game->textures->tile_size, &game->textures->tile_size);

	draw_map(game);

	mlx_key_hook(game->mlx_win, handle_keys, game);
	mlx_hook(game->mlx_win, 17, 0, close_wind, game);

	mlx_loop(game->mlx);
	return (0);
}

char	**read_map(const char *filename)
{
	int		fd;
	char	*line;
	char	**map;
	int		lines;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);

	map = NULL;
	lines = 0;
	while ((line = get_next_line(fd)))
	{
		map = realloc(map, (lines + 1) * sizeof(char *));
		map[lines] = line;
		lines++;
	}
	map = realloc(map, (lines + 1) * sizeof(char *));
	map[lines] = NULL;
	close(fd);
	return (map);
}

void	draw_map(t_game *game)
{
	void	*img;
	int		x;
	int		y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			img = game->textures->floor;

			if (game->map[y][x] == '1')
				img = game->textures->wall;
			else if (game->map[y][x] == 'P')
				img = game->textures->player;
			else if (game->map[y][x] == 'C')
				img = game->textures->collec;
			else if (game->map[y][x] == 'E')
				img = game->textures->exit;

			mlx_put_image_to_window(game->mlx, game->mlx_win, img, x * game->textures->tile_size, y * game->textures->tile_size);
			x++;
		}
		y++;
	}
}


// int	count_lines(char *mapname)
// {
// 	int		fd;
// 	int		count;
// 	char	*line;

// 	count = 0;
// 	fd = open(mapname, O_RDONLY);
// 	line = get_next_line(fd);
// 	if (fd == -1)
// 		return (-1);
// 	while (line)
// 	{
// 		count++;
// 		free(line);
// 	}
// 	close(fd);
// 	return (count);
// }

// void	print_map(char **map)
// {
// 	int	i;

// 	i = 0;
// 	while (map[i])
// 		ft_printf("%s", map[i++]);
// }

// void	free_map(char **map)
// {
// 	int	i;

// 	i = 0;
// 	while (map[i])
// 		free(map[i]);
// 	free(map);
// }
