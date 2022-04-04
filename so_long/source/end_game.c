/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaragre <ymaragre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:12:36 by ymaragre          #+#    #+#             */
/*   Updated: 2022/04/04 12:25:50 by ymaragre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_win(t_data *data)
{
	int	i;

	i = 1;
	mlx_put_image_to_window(data->mlx, data->win,
		data->spider.win, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win,
		data->map.string[0], 0, SIZE_PIXEL * SIZE_WIN);
	while (i < SIZE_WIN - 1)
		mlx_put_image_to_window(data->mlx, data->win,
			data->map.string[1], SIZE_PIXEL * i++, SIZE_PIXEL * SIZE_WIN);
	mlx_put_image_to_window(data->mlx, data->win,
		data->map.string[2], SIZE_PIXEL * i, SIZE_PIXEL * SIZE_WIN);
	mlx_string_put(data->mlx, data->win, SIZE_PIXEL * SIZE_WIN / 2 - 47,
		SIZE_PIXEL * SIZE_WIN + 16, 0xFFFFFF, "YOU WIN");
}

void	end_win(t_data *data)
{
	data->flags.end = 1;
	sleep(1);
}

void	draw_loss(t_data *data)
{
	int	i;

	i = 1;
	mlx_put_image_to_window(data->mlx, data->win,
		data->map.fon, data->map.x, data->map.y);
	mlx_put_image_to_window(data->mlx, data->win,
		data->spider.loss, 0, 0);
	draw_evil_wasp(data);
	mlx_put_image_to_window(data->mlx, data->win,
		data->map.string[0], 0, SIZE_PIXEL * SIZE_WIN);
	while (i < SIZE_WIN - 1)
		mlx_put_image_to_window(data->mlx, data->win,
			data->map.string[1], SIZE_PIXEL * i++, SIZE_PIXEL * SIZE_WIN);
	mlx_put_image_to_window(data->mlx, data->win,
		data->map.string[2], SIZE_PIXEL * i, SIZE_PIXEL * SIZE_WIN);
	mlx_string_put(data->mlx, data->win, SIZE_PIXEL * SIZE_WIN / 2 - 47,
		SIZE_PIXEL * SIZE_WIN + 16, 0xFFFFFF, "YOU LOSE");
}

static void	end_loss(t_data *data)
{
	data->flags.end = 2;
	sleep(1);
}

void	check_end(t_data *data, int i)
{
	if ((data->wasp[i].x + 16 >= (SIZE_WIN / 2) * SIZE_PIXEL
			&& data->wasp[i].y + 20 >= (SIZE_WIN / 2) * SIZE_PIXEL
			&& data->wasp[i].x + 16 <= (SIZE_WIN / 2 + 1) * SIZE_PIXEL
			&& data->wasp[i].y + 20 <= (SIZE_WIN / 2 + 1) * SIZE_PIXEL)
		|| (data->wasp[i].x + SIZE_PIXEL - 22 >= (SIZE_WIN / 2) * SIZE_PIXEL
			&& data->wasp[i].y + SIZE_PIXEL - 17 >= (SIZE_WIN / 2) * SIZE_PIXEL
			&& data->wasp[i].x + SIZE_PIXEL - 22
			<= (SIZE_WIN / 2 + 1) * SIZE_PIXEL
			&& data->wasp[i].y + SIZE_PIXEL - 17
			<= (SIZE_WIN / 2 + 1) * SIZE_PIXEL)
		|| (data->wasp[i].x + 16 >= (SIZE_WIN / 2) * SIZE_PIXEL
			&& data->wasp[i].y + SIZE_PIXEL - 17 >= (SIZE_WIN / 2) * SIZE_PIXEL
			&& data->wasp[i].x + 16 <= (SIZE_WIN / 2 + 1) * SIZE_PIXEL
			&& data->wasp[i].y + SIZE_PIXEL - 17
			<= (SIZE_WIN / 2 + 1) * SIZE_PIXEL)
		|| (data->wasp[i].x + SIZE_PIXEL - 22 >= (SIZE_WIN / 2) * SIZE_PIXEL
			&& data->wasp[i].y + 20 >= (SIZE_WIN / 2) * SIZE_PIXEL
			&& data->wasp[i].x + SIZE_PIXEL - 22
			<= (SIZE_WIN / 2 + 1) * SIZE_PIXEL
			&& data->wasp[i].y + 20 <= (SIZE_WIN / 2 + 1) * SIZE_PIXEL))
		end_loss(data);
}
