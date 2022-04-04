/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaragre <ymaragre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:32:52 by ymaragre          #+#    #+#             */
/*   Updated: 2022/03/01 20:32:52 by ymaragre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

int	ft_strcmp(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

int	count_rows(int fd)
{
	int		rows;
	char	*row;

	rows = 0;
	row = get_next_line(fd);
	while (row)
	{
		rows++;
		free(row);
		row = get_next_line(fd);
	}
	return (rows);
}

void	open_map(char *file_name, t_map *map)
{
	int		fd;
	int		i;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		err("the map cannot be opened");
	map->rows = count_rows(fd);
	close(fd);
	if (map->rows < 3)
		err("invalid map");
	map->arr = (char **) malloc(sizeof(char *) * (map->rows + 1));
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		err("the map cannot be opened");
	i = 0;
	while (i < map->rows)
		(map->arr)[i++] = get_next_line(fd);
	close(fd);
	(map->arr)[i] = NULL;
}
