/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maati <maati@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-31 19:02:59 by maati             #+#    #+#             */
/*   Updated: 2025-03-31 19:02:59 by maati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static char	*read_map_content(int fd)
{
	char	*line;
	char	*map_content;
	char	*temp;

	map_content = ft_strdup("");
	if (!map_content)
		return (NULL);
	while ((line = get_next_line(fd)) != NULL)
	{
		temp = map_content;
		map_content = ft_strjoin(map_content, line);
		free(temp);
		free(line);
		if (!map_content)
			return (NULL);
	}
	return (map_content);
}

char	**read_map(const char *file_path)
{
	int		fd;
	char	*map_content;
	char	**map;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (write(2, "Error: failed to open map file\n", 31), NULL);
	map_content = read_map_content(fd);
	close(fd);
	if (!map_content)
		return (write(2, "Error: failed to read map content\n", 34), NULL);
	map = ft_split(map_content, '\n');
	free(map_content);
	if (!map)
		write(2, "Error: failed to parse map\n", 27);
	return (map);
}
