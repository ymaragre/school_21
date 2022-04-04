/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaragre <ymaragre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:32:05 by ymaragre          #+#    #+#             */
/*   Updated: 2022/03/01 20:32:05 by ymaragre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# elif BUFFER_SIZE <= 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define SIZE_PIXEL 59
# define SIZE_WIN 11

# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"

# include "struct.h"

int		correct_name(char *name);
int		correct_map(t_data *data);
int		count_rows(int fd);
void	open_map(char *file_name, t_map *map);

int		key_press(int key, t_data *data);
int		key_release(int key, t_data *data);
int		key_no_press(t_data *data);
int		end_game(t_data *data);
void	end_win(t_data *data);

void	check_end(t_data *data, int i);

void	draw_enemy(t_data *data, int i);
void	game(t_data *data);
void	draw_win(t_data *data);
void	draw_loss(t_data *data);
void	draw_evil_wasp(t_data *data);

void	up(t_data *data);
void	down(t_data *data);
void	left(t_data *data);
void	right(t_data *data);

int		ft_strlen(char *str);
void	err(char *str);
int		ft_strcmp(const char *str1, const char *str2);
void	enemy_init(t_data *data, int i);
t_data	*data_init(char *map_name);
int		ft_printnbr(int n);
char	*ft_itoa(int n);

char	*get_next_line(int fd);
int		read_save_line(char **line, char **str);
int		read_to_line(char **str1, char *str2, int len);

#endif