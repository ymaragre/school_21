/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaragre <ymaragre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 19:23:44 by ymaragre          #+#    #+#             */
/*   Updated: 2022/04/04 12:26:12 by ymaragre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	len_to_nl(char *str, int len)
{
	int	i;

	i = 0;
	while (len-- > 0)
		if (str[i++] == '\n')
			return (i);
	return (i);
}

static int	copy_str(char **save_line, int len, int len_nl, char **line)
{
	char	*copied;
	int		j;

	j = 0;
	copied = (char *) malloc(len - len_nl + 1);
	if (!copied)
	{
		free(line);
		line = NULL;
		return (1);
	}
	while (len_nl < len)
		copied[j++] = save_line[0][len_nl++];
	copied[j] = '\0';
	free(*save_line);
	*save_line = copied;
	return (1);
}

int	read_save_line(char **line, char **save_line)
{
	int		len;
	int		len_nl;
	int		i;

	len = ft_strlen(*save_line);
	len_nl = len_to_nl(*save_line, len);
	*line = (char *) malloc(len_nl + 1);
	if (!*line)
		return (0);
	i = -1;
	while (++i < len_nl)
		line[0][i] = save_line[0][i];
	line[0][i--] = '\0';
	if (len != len_nl)
		return (copy_str(save_line, len, len_nl, line));
	if (*save_line)
	{
		free(*save_line);
		*save_line = NULL;
	}
	if (line[0][i] == '\n')
		return (1);
	return (0);
}

int	read_to_line(char **line, char *str, int len_str)
{
	char			*copy_line;
	char			*new_str;
	unsigned int	i;
	unsigned int	len;
	int				len_nl;

	copy_line = *line;
	len_nl = len_to_nl(str, len_str);
	len = ft_strlen(copy_line) + len_nl;
	new_str = (char *) malloc(len + 1);
	if (!new_str)
		return (-2);
	i = 0;
	while (*copy_line)
		new_str[i++] = *(copy_line++);
	while (i < len)
		new_str[i++] = *(str++);
	new_str[i] = '\0';
	free(*line);
	*line = new_str;
	if (len_nl == len_str && new_str[--i] == '\n')
		return (-1);
	else
		return (len_nl);
}
