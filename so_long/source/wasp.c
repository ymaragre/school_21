/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaragre <ymaragre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:51:02 by ymaragre          #+#    #+#             */
/*   Updated: 2022/04/04 12:27:57 by ymaragre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>

static void	init_sprite_enemy(t_data *data, int i)
{
	data->wasp[i].img[1][0] = mlx_xpm_file_to_image(data->mlx,
			"image/wasp-right-one.xpm", &(data->size), &(data->size));
	data->wasp[i].img[1][1] = mlx_xpm_file_to_image(data->mlx,
			"image/wasp-right-two.xpm", &(data->size), &(data->size));
	data->wasp[i].img[0][0] = mlx_xpm_file_to_image(data->mlx,
			"image/wasp-left-one.xpm", &(data->size), &(data->size));
	data->wasp[i].img[0][1] = mlx_xpm_file_to_image(data->mlx,
			"image/wasp-left-two.xpm", &(data->size), &(data->size));
	if (!(data->wasp[i].img[0][0]) || !(data->wasp[i].img[0][1])
		|| !(data->wasp[i].img[1][1]) || !(data->wasp[i].img[1][0]))
		err("the xpm cannot be opened");
}

void	enemy_init(t_data *data, int i)
{
	srand(time(NULL) + 87 * i);
	data->wasp[i].x = rand() % 11;
	if (data->wasp[i].x < 2 || data->wasp[i].x > 8)
		data->wasp[i].y = rand() % 11;
	else
		data->wasp[i].y = rand() % 2 + 9 * (rand() % 2);
	data->wasp[i].x *= SIZE_PIXEL;
	data->wasp[i].y *= SIZE_PIXEL;
	data->wasp[i].orient_x = rand() % 2;
	data->wasp[i].orient_y = rand() % 3 - 1;
	data->wasp[i].step = 0;
	init_sprite_enemy(data, i);
}

static void	move_near_wall(t_data *data, int i)
{
	if (data->wasp[i].x < 0)
	{
		data->wasp[i].orient_x = 1;
		data->wasp[i].x = 0;
	}
	if (data->wasp[i].y < 0)
	{
		data->wasp[i].orient_y = 3;
		data->wasp[i].y = 0;
	}
	if (data->wasp[i].x > SIZE_PIXEL * (SIZE_WIN - 1))
	{
		data->wasp[i].orient_x = 0;
		data->wasp[i].x = SIZE_PIXEL * (SIZE_WIN - 1);
	}	
	if (data->wasp[i].y > SIZE_PIXEL * (SIZE_WIN - 1))
	{
		data->wasp[i].orient_y = -3;
		data->wasp[i].y = SIZE_PIXEL * (SIZE_WIN - 1);
	}
}

static void	move_wasp(t_data *data, int i)
{
	if (data->wasp[i].step == 30)
	{
		if (data->wasp[i].x == 0)
			data->wasp[i].orient_x = 1;
		else if (data->wasp[i].x == 10)
			data->wasp[i].orient_x = 0;
		else
			data->wasp[i].orient_x = rand() % 2;
		if (data->wasp[i].y == 0)
			data->wasp[i].orient_y = 1;
		else if (data->wasp[i].y == 10)
			data->wasp[i].orient_y = -1;
		else
			data->wasp[i].orient_y = rand() % 7 - 3;
		data->wasp[i].step = 0;
	}
	data->wasp[i].y += data->wasp[i].orient_y;
	if (data->wasp[i].orient_x)
		data->wasp[i].x += 3;
	else
		data->wasp[i].x -= 3;
	move_near_wall(data, i);
	(data->wasp[i].step)++;
}

void	draw_enemy(t_data *data, int i)
{
	move_wasp(data, i);
	if (data->flags.fps < 12)
		mlx_put_image_to_window(data->mlx, data->win,
			data->wasp[i].img[data->wasp[i].orient_x][0],
			data->wasp[i].x, data->wasp[i].y);
	else
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->wasp[i].img[data->wasp[i].orient_x][1],
			data->wasp[i].x, data->wasp[i].y);
	}
	check_end(data, i);
}
