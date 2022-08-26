/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_on_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:34:12 by abouhaga          #+#    #+#             */
/*   Updated: 2022/08/07 23:32:29 by abouhaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	key_w(t_tools *s_long)
{
	if (position_check(s_long, s_long->sprite_pos_y - 1,
			s_long->sprite_pos_x) == 0)
		return ;
	s_long->img = mlx_xpm_file_to_image(s_long->mlx, "xpm_art/floor.xpm",
			&s_long->x, &s_long->y);
	mlx_put_image_to_window(s_long->mlx, s_long->win, s_long->img,
		s_long->sprite_pos_x * 46, s_long->sprite_pos_y * 46);
	mlx_destroy_image(s_long->mlx, s_long->img);
	s_long->img = mlx_xpm_file_to_image(s_long->mlx, "xpm_art/floor.xpm",
			&s_long->x, &s_long->y);
	mlx_put_image_to_window(s_long->mlx, s_long->win, s_long->img,
		s_long->sprite_pos_x * 46, (s_long->sprite_pos_y - 1) * 46);
	mlx_destroy_image(s_long->mlx, s_long->img);
	s_long->img = mlx_xpm_file_to_image(s_long->mlx, "xpm_art/up.xpm",
			&s_long->x, &s_long->y);
	mlx_put_image_to_window(s_long->mlx, s_long->win, s_long->img,
		s_long->sprite_pos_x * 46, (s_long->sprite_pos_y - 1) * 46);
	mlx_destroy_image(s_long->mlx, s_long->img);
	s_long->sprite_pos_y--;
	s_long->counter++;
	ft_printf("You have moved %d steps ! \n", s_long->counter);
}

void	key_s(t_tools *s_long)
{
	if (position_check(s_long, s_long->sprite_pos_y + 1,
			s_long->sprite_pos_x) == 0)
		return ;
	s_long->img = mlx_xpm_file_to_image(s_long->mlx, "xpm_art/floor.xpm",
			&s_long->x, &s_long->y);
	mlx_put_image_to_window(s_long->mlx, s_long->win, s_long->img,
		s_long->sprite_pos_x * 46, s_long->sprite_pos_y * 46);
	mlx_destroy_image(s_long->mlx, s_long->img);
	s_long->img = mlx_xpm_file_to_image(s_long->mlx, "xpm_art/floor.xpm",
			&s_long->x, &s_long->y);
	mlx_put_image_to_window(s_long->mlx, s_long->win, s_long->img,
		s_long->sprite_pos_x * 46, (s_long->sprite_pos_y + 1) * 46);
	mlx_destroy_image(s_long->mlx, s_long->img);
	s_long->img = mlx_xpm_file_to_image(s_long->mlx, "xpm_art/down.xpm",
			&s_long->x, &s_long->y);
	mlx_put_image_to_window(s_long->mlx, s_long->win, s_long->img,
		s_long->sprite_pos_x * 46, (s_long->sprite_pos_y + 1) * 46);
	mlx_destroy_image(s_long->mlx, s_long->img);
	s_long->sprite_pos_y++;
	s_long->counter++;
	ft_printf("You have moved %d steps ! \n", s_long->counter);
}

void	key_d(t_tools *s_long)
{
	if (position_check(s_long, s_long->sprite_pos_y,
			(s_long->sprite_pos_x + 1)) == 0)
		return ;
	s_long->img = mlx_xpm_file_to_image(s_long->mlx, "xpm_art/floor.xpm",
			&s_long->x, &s_long->y);
	mlx_put_image_to_window(s_long->mlx, s_long->win, s_long->img,
		(s_long->sprite_pos_x) * 46, s_long->sprite_pos_y * 46);
	mlx_destroy_image(s_long->mlx, s_long->img);
	s_long->img = mlx_xpm_file_to_image(s_long->mlx, "xpm_art/floor.xpm",
			&s_long->x, &s_long->y);
	mlx_put_image_to_window(s_long->mlx, s_long->win, s_long->img,
		(s_long->sprite_pos_x + 1) * 46, s_long->sprite_pos_y * 46);
	mlx_destroy_image(s_long->mlx, s_long->img);
	s_long->img = mlx_xpm_file_to_image(s_long->mlx, "xpm_art/right.xpm",
			&s_long->x, &s_long->y);
	mlx_put_image_to_window(s_long->mlx, s_long->win, s_long->img,
		(s_long->sprite_pos_x + 1) * 46, s_long->sprite_pos_y * 46);
	mlx_destroy_image(s_long->mlx, s_long->img);
	s_long->sprite_pos_x++;
	s_long->counter++;
	ft_printf("You have moved %d steps ! \n", s_long->counter);
}

void	key_a(t_tools *s_long)
{
	if (position_check(s_long, s_long->sprite_pos_y,
			(s_long->sprite_pos_x - 1)) == 0)
		return ;
	s_long->img = mlx_xpm_file_to_image(s_long->mlx, "xpm_art/floor.xpm",
			&s_long->x, &s_long->y);
	mlx_put_image_to_window(s_long->mlx, s_long->win, s_long->img,
		(s_long->sprite_pos_x) * 46, s_long->sprite_pos_y * 46);
	mlx_destroy_image(s_long->mlx, s_long->img);
	s_long->img = mlx_xpm_file_to_image(s_long->mlx, "xpm_art/floor.xpm",
			&s_long->x, &s_long->y);
	mlx_put_image_to_window(s_long->mlx, s_long->win, s_long->img,
		(s_long->sprite_pos_x - 1) * 46, s_long->sprite_pos_y * 46);
	mlx_destroy_image(s_long->mlx, s_long->img);
	s_long->img = mlx_xpm_file_to_image(s_long->mlx, "xpm_art/left.xpm",
			&s_long->x, &s_long->y);
	mlx_put_image_to_window(s_long->mlx, s_long->win, s_long->img,
		(s_long->sprite_pos_x - 1) * 46, s_long->sprite_pos_y * 46);
	mlx_destroy_image(s_long->mlx, s_long->img);
	s_long->sprite_pos_x--;
	s_long->counter++;
	ft_printf("You have moved %d steps ! \n", s_long->counter);
}

int	game_on(int keycode, t_tools *s_long)
{
	if (keycode == 53)
		exit (0);
	if (keycode == 13)
		key_w(s_long);
	else if (keycode == 1)
		key_s(s_long);
	else if (keycode == 0)
		key_a(s_long);
	else if (keycode == 2)
		key_d(s_long);
	add_brick(s_long);
	add_counter(keycode, s_long);
	open_door(s_long);
	return (0);
}
