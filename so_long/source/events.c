/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaragre <ymaragre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:54:32 by ymaragre          #+#    #+#             */
/*   Updated: 2022/04/04 12:25:56 by ymaragre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(t_data *data)
{
	(void) data;
	exit(0);
	return (0);
}

int	key_press(int key, t_data *data)
{
	static int	fps = 0;

	if (key == 53)
		exit (0);
	if (data->flags.end)
		return (0);
	if (data->flags.press == 0)
		fps = 0;
	if (!fps)
	{
		if (key == 0 || key == 123)
			left(data);
		if (key == 2 || key == 124)
			right(data);
		if (key == 1 || key == 125)
			down(data);
		if (key == 13 || key == 126)
			up(data);
	}
	else if (fps == 3)
			fps = -1;
	fps++;
	return (0);
}

int	key_release(int key, t_data *data)
{
	if ((key >= 0 && key <= 2)
		|| key == 13
		|| (key >= 123 && key <= 126))
		data->flags.press = 0;
	return (0);
}

int	key_no_press(t_data *data)
{
	if (data->flags.end == 0)
		game(data);
	if (data->flags.end == 1)
		draw_win(data);
	if (data->flags.end == 2)
		draw_loss(data);
	return (0);
}
