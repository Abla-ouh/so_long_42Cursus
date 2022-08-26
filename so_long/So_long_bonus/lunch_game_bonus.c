/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:52:11 by abouhaga          #+#    #+#             */
/*   Updated: 2022/08/07 23:23:35 by abouhaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_component(t_tools s_long, char component, int y, int x)
{
	if (component == 'P')
		s_long.img = mlx_xpm_file_to_image(s_long.mlx, "xpm_art/down.xpm",
				&s_long.x, &s_long.y);
	else if (component == 'C')
		s_long.img = mlx_xpm_file_to_image(s_long.mlx, "xpm_art/ch4.xpm",
				&s_long.x, &s_long.y);
	else if (component == 'E')
	{
		s_long.img = mlx_xpm_file_to_image(s_long.mlx, "xpm_art/doorclosed.xpm",
				&s_long.x, &s_long.y);
		mlx_put_image_to_window(s_long.mlx, s_long.win, s_long.img,
			x * 46, y * 46);
		mlx_destroy_image(s_long.mlx, s_long.img);
	}
	else if (component == '1')
	{
		s_long.img = mlx_xpm_file_to_image(s_long.mlx, "xpm_art/wall.xpm",
				&s_long.x, &s_long.y);
		mlx_put_image_to_window(s_long.mlx, s_long.win, s_long.img,
			x * 46, y * 46);
		return ;
	}
}

void	check_and_fill(t_tools s_long)
{
	int	i;
	int	j;

	i = 0;
	while (s_long.map[i])
	{
		j = 0;
		while (s_long.map[i][j])
		{
			put_component(s_long, s_long.map[i][j], i, j);
			j++;
		}
		i++;
	}
}

void	map_collectibles(t_tools *s_long)
{
	int	i;
	int	j;
	int	exit;

	i = 0;
	exit = 0;
	while (s_long->map[i])
	{
		j = 0;
		while (s_long->map[i][j])
		{
			if (s_long->map[i][j] == 'C')
				s_long->collectible++;
			if (s_long->map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (s_long->collectible == 0)
		ft_error('c');
	if (exit == 0)
		ft_error('x');
}

void	put_player(t_tools *s_long)
{
	s_long->sprite_pos_x = sprite_position(s_long, 'x');
	s_long->sprite_pos_y = sprite_position(s_long, 'y');
	s_long->img = mlx_xpm_file_to_image(s_long->mlx, "xpm_art/down.xpm",
			&s_long->x, &s_long->y);
	mlx_put_image_to_window(s_long->mlx, s_long->win, s_long->img,
		s_long->sprite_pos_x * 46, s_long->sprite_pos_y * 46);
	mlx_destroy_image(s_long->mlx, s_long->img);
}

void	lunch_game(t_tools s_long)
{
	s_long.map_width = dimensions(s_long.map, 'w');
	s_long.map_height = dimensions(s_long.map, 'h');
	s_long.mlx = mlx_init();
	s_long.win = mlx_new_window(s_long.mlx, s_long.map_width * 46,
			s_long.map_height * 46, "SO LONG AND THANKS TO ALL THE GOLD");
	s_long.img = mlx_xpm_file_to_image(s_long.mlx, "xpm_art/floor.xpm",
			&s_long.x, &s_long.y);
	fill_floor(s_long);
	check_and_fill(s_long);
	put_player(&s_long);
	map_collectibles(&s_long);
	mlx_hook(s_long.win, 2, 0, game_on, &s_long);
	mlx_hook(s_long.win, 17, 0, game_off, 0);
	mlx_loop_hook(s_long.mlx, animation, &s_long);
	mlx_loop(s_long.mlx);
}
