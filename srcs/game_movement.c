/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:40:22 by macaruan          #+#    #+#             */
/*   Updated: 2025/04/03 16:06:55 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	handle_player_movement(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
	{
		game->collected++;
		game->map[new_y][new_x] = '0';
	}
	else if (game->map[new_y][new_x] == 'E')
	{
		if (game->collected == game->total_collec)
		{
			ft_printf("%d déplacements effectués\n", game->move_count);
			close_window(game);
		}
		return ;
	}
	if (game->map[game->player_y][game->player_x] != 'E')
		game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[new_y][new_x] = 'P';
	game->move_count++;
	ft_printf("%d\n", game->move_count);
	draw_map(game);
}

void	move_player(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_y < 0 || new_x >= game->width || new_y >= game->height)
		return ;
	if (game->map[new_y][new_x] == '1')
		return ;
	handle_player_movement(game, new_x, new_y);
}

int	handle_keys(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		close_window(game);
	else if (keycode == W_KEY)
		move_player(game, game->player_x, game->player_y - 1);
	else if (keycode == S_KEY)
		move_player(game, game->player_x, game->player_y + 1);
	else if (keycode == A_KEY)
		move_player(game, game->player_x - 1, game->player_y);
	else if (keycode == D_KEY)
		move_player(game, game->player_x + 1, game->player_y);
	return (0);
}

int	validate_input(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		write(2, "Error: incorrect number of arguments\n", 37);
		return (0);
	}
	if (!check_map_type(argv[1]))
	{
		write(2, "Error: map file not a .ber\n", 27);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error: failed to open map file\n", 31);
		return (0);
	}
	close(fd);
	return (1);
}
