/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:30:37 by macaruan          #+#    #+#             */
/*   Updated: 2025/03/27 17:42:18 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

# include "../Libft/inc/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"


typedef struct s_textures
{
	void	*player;
	void	*wall;
	void	*floor;
	void	*exit;
	void	*collec;
	int		tile_size;
}	t_textures;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	int		player_x;
	int		player_y;
	int		total_collec;
	int		collected;
	int		move_count;
	int		width;
	int		height;
	t_textures	*textures;
}	t_game;

// EXIT.C

void	free_resources(t_game *game);
void	close_game(t_game *game);
int		close_window(t_game *game);

// FLOODFILL.C

void	floodfill(char **map, int x, int y, t_game *game);
int		is_map_solvable(t_game *game);

// GAME_MOVEMENT.C

void	move_player(t_game *game, int new_x, int new_y);
int		handle_keys(int keycode, t_game *game);
int		validate_input(int argc, char **argv);

// GAME_UTILS.C

void	find_player_loc(t_game *game);
void	count_collec(t_game *game);
void	handle_error(const char *message, t_game *game);
void	init_textures_struct(t_game *game);
void	init_game(t_game *game, const char *map_path);
int		validate_input(int argc, char **argv);

// MAP_CHECKER.C

int	is_valid_map_char(char c);
int	check_map_type(const char *filename);
int	check_map_rectangular(t_game *game);
int	count_map_elements(t_game *game);
int	is_map_enclosed(t_game *game);
int	validate_map(t_game *game);

// MAP_UTILS.C

void	draw_map(t_game *game);
void	draw_tile(t_game *game, int x, int y, void *texture);
void	free_map(char **map);
void	get_map_dimensions(char **map, int *width, int *height);
char	*trim_newline(char *str);
char	**copy_map(char **map);

// TEXTURES_UTILS.C

void	init_textures(t_game *game);
void	free_textures(t_game *game);

#endif
