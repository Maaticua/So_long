/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:40:22 by macaruan          #+#    #+#             */
/*   Updated: 2025/03/31 17:14:12 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'C')
	{
		game->collected++;
		game->map[new_y][new_x] = '0';
	}
	if (game->map[new_y][new_x] == 'E' && game->collected == game->total_collec)
	{
		ft_printf("gg, %d deplacement fait\n", game->move_count);
		close_window(game);
	}
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->move_count++;
	ft_printf("%d\n", game->move_count);
	draw_map(game);
}
int	handle_keys(int keycode, t_game *game)
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
int	validate_input(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Error: incorrect number of arguments\n", 37);
		return (0);
	}
	if (!check_map_type(argv[1]))
		return (0);
	return (1);
}
