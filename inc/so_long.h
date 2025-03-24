/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:30:37 by macaruan          #+#    #+#             */
/*   Updated: 2025/03/24 17:03:31 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define ESC_KEY 65307

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
	t_textures	*textures;
}	t_game;

int	close_wind(t_game *game);
int	handle_keys(int keycode, t_game *game);
char	**read_map(const char *filename);
void	draw_map(t_game *game);

#endif
