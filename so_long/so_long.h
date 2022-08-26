/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:56:56 by abouhaga          #+#    #+#             */
/*   Updated: 2022/08/04 20:09:10 by abouhaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct s_tools
{
	char	**map;
	int		map_width;
	int		map_height;
	void	*mlx;
	void	*win;
	void	*img;
	int		x;
	int		y;
	int		sprite_pos_x;
	int		sprite_pos_y;
	int		collectible;
	int		counter;
}	t_tools;

char	*get_next_line(int fd);
char	**validate_map(char *av);
char	*read_file(int fd);
void	ft_error(char c);
void	lunch_game(t_tools s_long);
int		game_on(int keycode, t_tools *s_long);
void	add_brick(t_tools *s_long);
int		game_off(void);
int		position_check(t_tools *s_long, int y, int x);
int		sprite_position(t_tools *s_long, char c);
int		dimensions(char **lines, char c);
void	add_counter(int key, t_tools *s_long);
int		animation(t_tools *s_long);
void	add_anim(t_tools *s_long, char *path);
int		game_enemy_anim(t_tools *s_long);
void	put_floor(t_tools *s_long, int x, int y);
void	fill_floor(t_tools s_long);
void	enemy_frames(t_tools *s_long);
void	open_door(t_tools *s_long);
void	put_wall_floor(t_tools *s_long);
#endif