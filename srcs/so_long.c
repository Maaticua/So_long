/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:30:45 by macaruan          #+#    #+#             */
/*   Updated: 2025/03/21 14:52:52 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(char **maps)
{
	char **maps;
}

char	**read_map(char *mapname)
{
	int		lines;
	char	**map;
	int		fd;
	int		i;
	char	*line;

	line = get_next_line(fd);
	lines = count_lines(mapname);
	if (lines <= 0)
		return (NULL);
	map = malloc ((lines +1) * sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(mapname, O_RDONLY);
	if (fd == -1)
	{
		free(map);
		return (NULL);
	}
	i = 0;
	while (line)
		map[i++] = line;
	map[i] = NULL;
	clode(fd);
	return (map);
}

int	count_lines(char *mapname)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(mapname, O_RDONLY);
	line = get_next_line(fd);
	if (fd == -1)
		return (-1);
	while (line)
	{
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		ft_printf("%s", map[i++]);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i]);
	free(map);
}
