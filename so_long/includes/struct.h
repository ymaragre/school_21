/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaragre <ymaragre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 06:34:57 by ymaragre          #+#    #+#             */
/*   Updated: 2022/03/23 14:19:16 by ymaragre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

# ifndef NUMBER_WASP
#  define NUMBER_WASP 2
# elif NUMBER_WASP <= 0
#  undef NUMBER_WASP
#  define NUMBER_WASP 2
# endif

/*
	0 - down
	1 - right
	2 - up
	3 - left
*/
typedef struct s_pers
{
	int		x;
	int		y;
	int		orient;
	void	*img[4][3];
	void	*win;
	void	*loss;
}	t_pers;

typedef struct s_enemy
{
	int		x;
	int		y;
	int		orient_x;
	int		orient_y;
	int		step;
	void	*img[2][2];
}	t_enemy;

typedef struct s_map
{
	char	**arr;
	int		x;
	int		y;
	int		rows;
	int		cols;
	void	*fon;
	void	*web;
	void	*fly[2];
	void	*exits[2];
	void	*string[3];
}	t_map;

typedef struct s_flags
{
	int		end;
	int		fps;
	int		press;
	int		flies;
	int		steps;
}	t_flags;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_pers	spider;
	t_enemy	wasp[NUMBER_WASP];
	t_map	map;
	t_flags	flags;
	int		size;
	int		size_fon_w;
	int		size_fon_h;
	int		size_end;
}	t_data;

#endif
