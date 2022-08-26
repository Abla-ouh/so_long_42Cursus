/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 08:56:51 by abouhaga          #+#    #+#             */
/*   Updated: 2022/08/07 21:32:49 by abouhaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_floor(t_tools *s_long, int x, int y)
{
	s_long->img = mlx_xpm_file_to_image(s_long->mlx, "xpm_art/floor.xpm",
			&s_long->x, &s_long->y);
	mlx_put_image_to_window(s_long->mlx, s_long->win, s_long->img,
		x * 46, y * 46);
	mlx_destroy_image(s_long->mlx, s_long->img);
}

void	add_anim(t_tools *s_long, char *path)
{
	int	i;
	int	j;

	i = 0;
	while (s_long->map[i])
	{
		j = 0;
		while (s_long->map[i][j])
		{
			if (s_long->map[i][j] == 'C')
			{
				put_floor(s_long, j, i);
				s_long->img = mlx_xpm_file_to_image(s_long->mlx, path,
						&s_long->x, &s_long->y);
				mlx_put_image_to_window(s_long->mlx, s_long->win, s_long->img,
					j * 46, i * 46);
				mlx_destroy_image(s_long->mlx, s_long->img);
			}
			j++;
		}
		i++;
	}
}

void	frame_loop_helper(int *frame)
{
	if (*frame == 0 || *frame == 1 || *frame == 2)
		*frame = *frame + 1;
	else if (*frame == 3)
		*frame = 0;
}

void	collectible_frames(t_tools *s_long)
{
	static int	timer;
	static int	frame;

	if (timer > 6000)
	{
		if (frame == 0)
			add_anim(s_long, "xpm_art/ch1.xpm");
		else if (frame == 1)
			add_anim(s_long, "xpm_art/ch2.xpm");
		else if (frame == 2)
			add_anim(s_long, "xpm_art/ch3.xpm");
		else if (frame == 3)
			add_anim(s_long, "xpm_art/ch4.xpm");
		frame_loop_helper(&frame);
		timer = 0;
	}
	else
		timer++;
}

int	animation(t_tools *s_long)
{
	collectible_frames(s_long);
	enemy_frames(s_long);
	return (0);
}
