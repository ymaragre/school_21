/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaragre <ymaragre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:30:40 by ymaragre          #+#    #+#             */
/*   Updated: 2022/03/01 20:30:40 by ymaragre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2 || correct_name(argv[1]))
		err("invalid arguments");
	data = data_init(argv[1]);
	mlx_loop_hook(data->mlx, key_no_press, data);
	mlx_hook(data->win, 2, 0, key_press, data);
	mlx_hook(data->win, 3, 0, key_release, data);
	mlx_hook(data->win, 17, 0, end_game, data);
	mlx_loop(data->mlx);
	exit(0);
}
