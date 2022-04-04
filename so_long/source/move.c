/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaragre <ymaragre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 07:50:17 by ymaragre          #+#    #+#             */
/*   Updated: 2022/04/04 12:26:48 by ymaragre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	down(t_data *data)
{
	int	i;

	data->flags.steps += 1;
	data->flags.press = 1;
	data->spider.orient = 0;
	if (data->map.arr[data->spider.y + 1][data->spider.x] == 'C')
	{
		data->flags.flies -= 1;
		data->map.arr[data->spider.y + 1][data->spider.x] = '0';
	}
	if (data->map.arr[data->spider.y + 1][data->spider.x] == 'E'
		&& data->flags.flies == 0)
		end_win(data);
	if (data->map.arr[data->spider.y + 1][data->spider.x] == '0')
	{
		data->spider.y += 1;
		data->map.y -= 1;
		i = 0;
		while (i < NUMBER_WASP)
			data->wasp[i++].y -= SIZE_PIXEL;
	}
}

void	up(t_data *data)
{
	int	i;

	data->flags.steps += 1;
	data->flags.press = 1;
	data->spider.orient = 2;
	if (data->map.arr[data->spider.y - 1][data->spider.x] == 'C')
	{
		data->flags.flies -= 1;
		data->map.arr[data->spider.y - 1][data->spider.x] = '0';
	}
	if (data->map.arr[data->spider.y - 1][data->spider.x] == 'E'
		&& data->flags.flies == 0)
		end_win(data);
	if (data->map.arr[data->spider.y - 1][data->spider.x] == '0')
	{
		data->spider.y -= 1;
		data->map.y += 1;
		i = 0;
		while (i < NUMBER_WASP)
			data->wasp[i++].y += SIZE_PIXEL;
	}
}

void	left(t_data *data)
{
	int	i;

	data->flags.steps += 1;
	data->flags.press = 1;
	data->spider.orient = 3;
	if (data->map.arr[data->spider.y][data->spider.x - 1] == 'C')
	{
		data->flags.flies -= 1;
		data->map.arr[data->spider.y][data->spider.x - 1] = '0';
	}
	if (data->map.arr[data->spider.y][data->spider.x - 1] == 'E'
		&& data->flags.flies == 0)
		end_win(data);
	if (data->map.arr[data->spider.y][data->spider.x - 1] == '0')
	{
		data->spider.x -= 1;
		data->map.x += 4;
		i = 0;
		while (i < NUMBER_WASP)
			data->wasp[i++].x += SIZE_PIXEL;
	}
}

void	right(t_data *data)
{
	int	i;

	data->flags.steps += 1;
	data->flags.press = 1;
	data->spider.orient = 1;
	if (data->map.arr[data->spider.y][data->spider.x + 1] == 'C')
	{
		data->flags.flies -= 1;
		data->map.arr[data->spider.y][data->spider.x + 1] = '0';
	}
	if (data->map.arr[data->spider.y][data->spider.x + 1] == 'E'
		&& data->flags.flies == 0)
		end_win(data);
	if (data->map.arr[data->spider.y][data->spider.x + 1] == '0')
	{
		data->spider.x += 1;
		data->map.x -= 4;
		i = 0;
		while (i < NUMBER_WASP)
			data->wasp[i++].x -= SIZE_PIXEL;
	}
}
