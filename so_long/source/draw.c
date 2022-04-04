/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaragre <ymaragre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:33:19 by ymaragre          #+#    #+#             */
/*   Updated: 2022/04/04 12:25:43 by ymaragre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_exit(t_data *data, int k, int l)
{
	if (data->flags.flies)
		mlx_put_image_to_window(data->mlx, data->win,
			data->map.exits[0], SIZE_PIXEL * l, SIZE_PIXEL * k);
	else
		mlx_put_image_to_window(data->mlx, data->win,
			data->map.exits[1], SIZE_PIXEL * l, SIZE_PIXEL * k);
}

static void	draw_map(t_data *data, int k, int l)
{
	int			i;
	int			j;

	j = data->spider.y - SIZE_WIN / 2 + k;
	i = data->spider.x - SIZE_WIN / 2 + l;
	if ((i < 0 || i >= data->map.cols) || (j < 0 || j >= data->map.rows))
		return ;
	if (data->map.arr[j][i] == '0' || data->map.arr[j][i] == 'C'
		|| data->map.arr[j][i] == 'E')
		mlx_put_image_to_window(data->mlx, data->win,
			data->map.web, SIZE_PIXEL * l, SIZE_PIXEL * k);
	if (data->map.arr[j][i] == 'C')
	{
		if (data->flags.fps < 6
			|| (data->flags.fps > 12 && data->flags.fps < 18))
			mlx_put_image_to_window(data->mlx, data->win,
				data->map.fly[0], SIZE_PIXEL * l, SIZE_PIXEL * k);
		else
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->map.fly[1], SIZE_PIXEL * l, SIZE_PIXEL * k);
		}
	}
	if (data->map.arr[j][i] == 'E')
		draw_exit(data, k, l);
}

static void	draw_spider(t_data *data)
{
	if (data->flags.press == 0)
		mlx_put_image_to_window(data->mlx, data->win,
			data->spider.img[data->spider.orient][0],
			(SIZE_WIN / 2) * SIZE_PIXEL, (SIZE_WIN / 2) * SIZE_PIXEL);
	else
	{
		if (data->flags.fps < 12)
			mlx_put_image_to_window(data->mlx, data->win,
				data->spider.img[data->spider.orient][1],
				(SIZE_WIN / 2) * SIZE_PIXEL, (SIZE_WIN / 2) * SIZE_PIXEL);
		else
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->spider.img[data->spider.orient][2],
				(SIZE_WIN / 2) * SIZE_PIXEL, (SIZE_WIN / 2) * SIZE_PIXEL);
		}
	}
}

static void	draw_string(t_data *data)
{
	int		i;
	char	*str;

	i = 1;
	mlx_put_image_to_window(data->mlx, data->win,
		data->map.string[0], 0, SIZE_PIXEL * SIZE_WIN);
	while (i < SIZE_WIN - 1)
		mlx_put_image_to_window(data->mlx, data->win,
			data->map.string[1], SIZE_PIXEL * i++, SIZE_PIXEL * SIZE_WIN);
	mlx_put_image_to_window(data->mlx, data->win,
		data->map.string[2], SIZE_PIXEL * i, SIZE_PIXEL * SIZE_WIN);
	mlx_string_put(data->mlx, data->win, 26, SIZE_PIXEL * SIZE_WIN + 16,
		0xFFFFFF, "steps: ");
	str = ft_itoa(data->flags.steps);
	mlx_string_put(data->mlx, data->win, 114, SIZE_PIXEL * SIZE_WIN + 16,
		0xFFFFFF, str);
	free(str);
	mlx_string_put(data->mlx, data->win, SIZE_PIXEL * SIZE_WIN / 2,
		SIZE_PIXEL * SIZE_WIN + 16, 0xFFFFFF, "flies: ");
		str = ft_itoa(data->flags.flies);
	mlx_string_put(data->mlx, data->win, SIZE_PIXEL * SIZE_WIN / 2 + 88,
		SIZE_PIXEL * SIZE_WIN + 16, 0xFFFFFF, str);
	free(str);
}

void	game(t_data *data)
{
	int	k;
	int	l;

	mlx_put_image_to_window(data->mlx, data->win,
		data->map.fon, data->map.x, data->map.y);
	k = 0;
	while (k < SIZE_WIN)
	{
		l = 0;
		while (l < SIZE_WIN)
			draw_map(data, k, l++);
		k++;
	}
	draw_spider(data);
	k = 0;
	while (k < NUMBER_WASP)
		draw_enemy(data, k++);
	draw_string(data);
	if (++(data->flags.fps) > 24)
		data->flags.fps = 0;
}
