/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaragre <ymaragre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 19:22:44 by ymaragre          #+#    #+#             */
/*   Updated: 2022/04/04 12:26:27 by ymaragre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	read_to_save(char **save, char *str, int i, int len)
{
	int	j;

	*save = (char *) malloc(len - i + 1);
	if (!save)
		return ;
	j = 0;
	while (i < len)
		save[0][j++] = str[i++];
	save[0][j] = '\0';
}

static int	read_str(int fd, char **line, char **save)
{
	char	str[BUFFER_SIZE];
	int		len_line;
	int		len_line_nl;

	while (1)
	{
		len_line = read(fd, str, BUFFER_SIZE);
		if (!len_line && ft_strlen(*line))
			return (0);
		if (len_line <= 0)
			return (-1);
		len_line_nl = read_to_line(line, str, len_line);
		if (len_line_nl == -2)
			return (-1);
		if (len_line_nl == -1)
			return (0);
		if (len_line_nl < len_line)
		{
			read_to_save(save, str, len_line_nl, len_line);
			return (0);
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*save_line;
	char		*line;
	int			result;

	if (read_save_line(&line, &save_line))
		return (line);
	if (!line)
		return (NULL);
	result = read_str(fd, &line, &save_line);
	if (result == -1)
	{
		free(line);
		if (save_line)
			free(save_line);
		save_line = NULL;
		return (NULL);
	}
	return (line);
}
