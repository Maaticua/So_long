/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:30:45 by macaruan          #+#    #+#             */
/*   Updated: 2025/03/25 15:05:12 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	get_map_dimensions(char **map, int *width, int *height)
{
	int	y;
	int row_len;

	*width = 0;
	*height = 0;

	row_len = 0;
	y = 0;;
	while (map[y] != NULL)
	{
		row_len = 0;
		while (map[y][row_len] != '\n')
			row_len++;
		if (row_len > *width)
			*width = row_len;
		y++;
	}
	*height = y;
}

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
void	find_player_loc(t_game *game)
{
	int	x;
	int y;

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
				return;
			}
			x++;
		}
		y++;
	}
}
void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == '1')
		return;

	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;

	draw_map(game);
}
int handle_keys(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		close_wind(game);
	else if (keycode == W_KEY) // Haut
		move_player(game, game->player_x, game->player_y - 1);
	else if (keycode == S_KEY) // Bas
		move_player(game, game->player_x, game->player_y + 1);
	else if (keycode == A_KEY) // Gauche
		move_player(game, game->player_x - 1, game->player_y);
	else if (keycode == D_KEY) // Droite
		move_player(game, game->player_x + 1, game->player_y);
	return (0);
}


int	main(int ac, char **av)
{
	t_game	*game;
	int		map_width;
	int		map_height;

	if (ac != 2)
	{
		write(2, "incorect arguments \n", 21);
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

	game->map = read_map(av[1]);
	if (!game->map)
	{
		write(2, "Error: invalid map\n", 19);
		return (1);
	}
	find_player_loc(game);

	get_map_dimensions(game->map, &map_width, &map_height);

	game->textures->tile_size = 64;
	int window_width = map_width * game->textures->tile_size;
	int window_height = map_height * game->textures->tile_size;

	game->mlx_win = mlx_new_window(game->mlx, window_width, window_height, "so_long");
	if (!game->mlx_win)
	{
		free(game->mlx);
		free(game);
		write(2, "Error\n", 6);
		return (1);
	}

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
