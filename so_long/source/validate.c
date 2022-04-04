/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaragre <ymaragre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:33:12 by ymaragre          #+#    #+#             */
/*   Updated: 2022/03/01 20:33:12 by ymaragre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	correct_name(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (len < 5)
		return (1);
	if (ft_strcmp((name + len - 4), ".ber"))
		return (1);
	return (0);
}

static int	ft_strlen_validate(char *str)
{
	int	length;

	length = 0;
	while (str[length] && str[length] != '\n')
		length++;
	return (length);
}

static int	full_one(char *row)
{
	int	len;

	len = 0;
	while (row[len] && row[len] != '\n')
	{
		if (row[len] != '1')
			err("invalid map");
		len++;
	}
	return (len);
}

static void	correct_rows(int i, t_data *data, int *exits)
{
	int		j;

	j = 0;
	while (data->map.arr[i][j] && data->map.arr[i][j] != '\n')
	{
		if (data->map.arr[i][j] == 'E')
			(*exits)++;
		else if (data->map.arr[i][j] == 'C')
			(data->flags.flies)++;
		else if (data->map.arr[i][j] == 'P')
		{
			if (data->spider.x == 0 && data->spider.y == 0)
			{
				data->spider.x = j;
				data->spider.y = i;
				data->map.arr[i][j] = '0';
			}
			else
				err("invalid map");
		}
		else if (data->map.arr[i][j] != '0' && data->map.arr[i][j] != '1')
			err("invalid map");
		j++;
	}
}

int	correct_map(t_data *data)
{
	int	exits;
	int	i;

	exits = 0;
	i = 0;
	data->map.cols = full_one(*(data->map.arr));
	while (data->map.arr[i + 1])
	{
		if (ft_strlen_validate(data->map.arr[i]) != data->map.cols
			|| data->map.arr[i][0] != '1'
			|| data->map.arr[i][data->map.cols - 1] != '1')
			err("invalid map");
		correct_rows(i, data, &exits);
		i++;
	}
	if (full_one(data->map.arr[i]) != data->map.cols)
		err("invalid map");
	if (!exits || !(data->flags.flies)
		|| !(data->spider.x) || !(data->spider.y))
		err("invalid map");
	return (data->flags.flies);
}
