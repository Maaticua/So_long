/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:30:45 by macaruan          #+#    #+#             */
/*   Updated: 2025/03/27 19:22:32 by macaruan         ###   ########.fr       */
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
	int row_len;

	y = 0;
	*width = 0;
	*height = 0;
	while (map[y] != NULL)
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
		return;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
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
char **copy_map(char **map)
{
	int	y;
	char **cpy;

	y = 0;
	while (map[y])
		y++;

	cpy = malloc((y+1) * sizeof(char *));
	if (!cpy)
		return (NULL);
	y = 0;
	while (map[y])
	{
		cpy[y] = ft_strdup(map[y]);
		if (!cpy[y])
		{
			free_map(cpy);
			return (NULL);
		}
		y++;
	}
	cpy[y] = NULL;
	return (cpy);
}
int	check_map_type(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
	{
		write (2, "Error wrong map type", 21);
		return (0);
	}
	return (1);
}

char	**read_map(const char *filename)
{
	int		i;
	int		fd;
	int		lines;
	char	*line;
	char	**map;

	lines = 0;

	if (!check_map_type(filename))
		return (NULL);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (write(2, "Error: Cannot open map file\n", 27), NULL);

	while ((line = get_next_line(fd)))
	{
		if (line[0] != '\n')
			lines++;
		free(line);
	}
	close(fd);

	map = malloc((lines + 1) * sizeof(char *));
	if (!map)
		return (NULL);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(map);
		write(2, "Error: cannot reopen map file\n", 31);
		return (NULL);
	}

	i = 0;
	while ((line = get_next_line(fd)))
	{
		if (line[0] != '\n')
		{
			map[i] = trim_newline(line);
			i++;
		}
	}
	map[i] = NULL;
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

	if (game->map[new_y][new_x] == 'C')
	{
		game->collected++;
		game->map[new_y][new_x] = '0';
	}

	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collected == game->total_collec)
		{
			ft_printf("gg, %d deplacement fait\n", game->move_count);
			close_wind(game);
		}
		return;
	}

	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;

	game->move_count++;
	ft_printf("%d\n", game->move_count);

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
void	count_collec(t_game *game)
{
	int	x;
	int	y;

	y = 0;
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

int is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E');
}
void	floodfill(char **map, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || x >= game->width || y >= game->height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'V';
		return ;
	}
	map[y][x] = 'F';
	floodfill(map, x + 1, y, game);
	floodfill(map, x - 1, y, game);
	floodfill(map, x, y + 1, game);
	floodfill(map, x, y - 1, game);
}

int	is_map_solvable(t_game *game)
{
	int	x;
	int	y;
	char **map_temp;

	map_temp = copy_map(game->map);
	if(!map_temp)
		return (ft_printf("Error, map cpy failed"), 1);
	find_player_loc(game);
	floodfill(map_temp, game->player_x, game->player_y, game);

	y = -1;
	while (map_temp[++y])
	{
		x = -1;
		while (map_temp[y][++x])
		{
			if (map_temp[y][x] == 'C' || map_temp[y][x] == 'E')
			{
				ft_printf("Error ; map design is invalid\n");
				return (free_map(map_temp), 1);
			}
		}
	}
	return (free_map(map_temp), 1);
}
int validate_map(t_game *game)
{
	int y;
	int x;
	int player_count;
	int exit_count;
	int collect_count;
	int width;

	y = 0;
	player_count = 0;
	exit_count = 0;
	collect_count = 0;
	width = ft_strlen(game->map[0]);

	while (game->map[y])
	{
		if ((int)ft_strlen(game->map[y]) != width)
		{
			write(2, "Error: not rectangular\n", 20);
			return (0);
		}
		x = 0;
		while (game->map[y][x])
		{
			if (!is_valid_map_char(game->map[y][x]))
			{
				write(2, "Error: Invalid character\n", 26);
				return (0);
			}
			if (game->map[y][x] == 'P')
				player_count++;
			if (game->map[y][x] == 'E')
				exit_count++;
			if (game->map[y][x] == 'C')
				collect_count++;
			x++;
		}
		y++;
	}
	if (player_count != 1 || exit_count != 1 || collect_count < 1)
	{
		write(2, "Error: Map must have 1 player, 1 exit, and at least 1 collectible\n", 65);
		return (0);
	}

	if (!is_map_solvable(game))
	{
		write (2, "Error: unsolvable\n", 18);
		return (0);
	}

	return (1);
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

	if (!validate_map(game))
	{
		free_map(game->map);
		free(game);
		return (1);
	}

	find_player_loc(game);

	count_collec(game);
	game->collected = 0;
	game->move_count = 0;

	get_map_dimensions(game->map, &map_width, &map_height);

	game->textures->tile_size = 64;
	int window_width = (map_width -1) * game->textures->tile_size;
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
