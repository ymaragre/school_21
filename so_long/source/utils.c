/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaragre <ymaragre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:02:12 by ymaragre          #+#    #+#             */
/*   Updated: 2022/03/01 21:02:12 by ymaragre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	if (!str)
		return (length);
	while (str[length])
		length++;
	return (length);
}

void	err(char *str)
{
	write(2, "so_long: error: ", 16);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(1);
}

void	draw_evil_wasp(t_data *data)
{
	if (data->flags.fps < 12)
		mlx_put_image_to_window(data->mlx, data->win,
			data->wasp[0].img[0][0], 475, 255);
	else
		mlx_put_image_to_window(data->mlx, data->win,
			data->wasp[0].img[0][1], 475, 255);
	if (data->flags.fps < 12)
		mlx_put_image_to_window(data->mlx, data->win,
			data->wasp[0].img[1][0], 193, 190);
	else
		mlx_put_image_to_window(data->mlx, data->win,
			data->wasp[0].img[1][1], 193, 190);
	if (data->flags.fps < 12)
		mlx_put_image_to_window(data->mlx, data->win,
			data->wasp[0].img[0][0], 527, 58);
	else
		mlx_put_image_to_window(data->mlx, data->win,
			data->wasp[0].img[0][1], 527, 58);
	if (++(data->flags.fps) > 24)
		data->flags.fps = 0;
}
