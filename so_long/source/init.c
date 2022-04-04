/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaragre <ymaragre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 02:53:39 by ymaragre          #+#    #+#             */
/*   Updated: 2022/04/04 12:26:35 by ymaragre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_init(t_data *data, char *map_name)
{
	open_map(map_name, &(data->map));
	data->map.cols = 0;
	data->map.x = -152;
	data->map.y = -18;
	data->map.web = mlx_xpm_file_to_image(data->mlx, "image/cobweb.xpm",
			&(data->size), &(data->size));
	data->map.fly[0] = mlx_xpm_file_to_image(data->mlx, "image/fly-one.xpm",
			&(data->size), &(data->size));
	data->map.fly[1] = mlx_xpm_file_to_image(data->mlx, "image/fly-two.xpm",
			&(data->size), &(data->size));
	data->map.exits[0] = mlx_xpm_file_to_image(data->mlx,
			"image/cocoon-close.xpm", &(data->size), &(data->size));
	data->map.exits[1] = mlx_xpm_file_to_image(data->mlx,
			"image/cocoon-open.xpm", &(data->size), &(data->size));
	data->map.string[0] = mlx_xpm_file_to_image(data->mlx,
			"image/string-one.xpm", &(data->size), &(data->size));
	data->map.string[1] = mlx_xpm_file_to_image(data->mlx,
			"image/string-two.xpm", &(data->size), &(data->size));
	data->map.string[2] = mlx_xpm_file_to_image(data->mlx,
			"image/string-three.xpm", &(data->size), &(data->size));
	data->map.fon = mlx_xpm_file_to_image(data->mlx,
			"image/fon.xpm", &(data->size_fon_w), &(data->size_fon_h));
	if (!(data->map.web) || !(data->map.fly[0]) || !(data->map.fly[1])
		|| !(data->map.exits[0]) || !(data->map.exits[1]) || !(data->map.fon))
		err("the xpm cannot be opened");
}

static void	pers_sprite_init(t_data *data)
{
	data->spider.img[0][0] = mlx_xpm_file_to_image(data->mlx,
			"image/spider-down.xpm", &(data->size), &(data->size));
	data->spider.img[0][1] = mlx_xpm_file_to_image(data->mlx,
			"image/spider-down-one.xpm", &(data->size), &(data->size));
	data->spider.img[0][2] = mlx_xpm_file_to_image(data->mlx,
			"image/spider-down-two.xpm", &(data->size), &(data->size));
	data->spider.img[1][0] = mlx_xpm_file_to_image(data->mlx,
			"image/spider-right.xpm", &(data->size), &(data->size));
	data->spider.img[1][1] = mlx_xpm_file_to_image(data->mlx,
			"image/spider-right-one.xpm", &(data->size), &(data->size));
	data->spider.img[1][2] = mlx_xpm_file_to_image(data->mlx,
			"image/spider-right-two.xpm", &(data->size), &(data->size));
	data->spider.img[2][0] = mlx_xpm_file_to_image(data->mlx,
			"image/spider-up.xpm", &(data->size), &(data->size));
	data->spider.img[2][1] = mlx_xpm_file_to_image(data->mlx,
			"image/spider-up-one.xpm", &(data->size), &(data->size));
	data->spider.img[2][2] = mlx_xpm_file_to_image(data->mlx,
			"image/spider-up-two.xpm", &(data->size), &(data->size));
	data->spider.img[3][0] = mlx_xpm_file_to_image(data->mlx,
			"image/spider-left.xpm", &(data->size), &(data->size));
	data->spider.img[3][1] = mlx_xpm_file_to_image(data->mlx,
			"image/spider-left-one.xpm", &(data->size), &(data->size));
	data->spider.img[3][2] = mlx_xpm_file_to_image(data->mlx,
			"image/spider-left-two.xpm", &(data->size), &(data->size));
}

static void	pers_init(t_data *data)
{
	int	i;
	int	j;

	data->spider.x = 0;
	data->spider.y = 0;
	data->spider.orient = 0;
	pers_sprite_init(data);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 2)
			if (!(data->spider.img[i][j++]))
				err("the xpm cannot be opened");
		i++;
	}
	data->spider.win = mlx_xpm_file_to_image(data->mlx,
			"image/win.xpm", &(data->size_end), &(data->size_end));
	data->spider.loss = mlx_xpm_file_to_image(data->mlx,
			"image/loss.xpm", &(data->size_end), &(data->size_end));
}

static void	flags_init(t_data *data)
{
	int	i;

	data->flags.end = 0;
	data->flags.fps = 0;
	data->flags.press = 0;
	data->flags.steps = 0;
	data->flags.flies = 0;
	i = 0;
	while (i < 3)
		if (!(data->map.string[i++]))
			err("the xpm cannot be opened");
}

t_data	*data_init(char *map_name)
{
	t_data	*data;
	int		i;

	data = (t_data *) malloc(sizeof(t_data));
	if (!data)
		err("memory allocation error");
	data->size = SIZE_PIXEL;
	data->size_fon_h = 686;
	data->size_fon_w = 953;
	data->size_end = SIZE_PIXEL * SIZE_WIN;
	data->mlx = mlx_init();
	if (!data->mlx)
		err("mlx error");
	map_init(data, map_name);
	pers_init(data);
	flags_init(data);
	i = 0;
	while (i < NUMBER_WASP)
		enemy_init(data, i++);
	correct_map(data);
	data->win = mlx_new_window(data->mlx, SIZE_PIXEL * SIZE_WIN,
			SIZE_PIXEL * (SIZE_WIN + 1), "little spider");
	if (!data->win)
		err("mlx error");
	return (data);
}
