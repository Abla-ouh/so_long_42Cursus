/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_enemy_anim_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:19:30 by abouhaga          #+#    #+#             */
/*   Updated: 2022/08/07 21:32:57 by abouhaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	add_anim_enemy(t_tools *s_long, char *path)
{
	int	i;
	int	j;

	i = 0;
	while (s_long->map[i])
	{
		j = 0;
		while (s_long->map[i][j])
		{
			if (s_long->map[i][j] == 'G')
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

void	helper(int *frame)
{
	if (*frame == 0)
		*frame = *frame + 1;
	else if (*frame == 1)
		*frame = 0;
}

void	enemy_frames(t_tools *s_long)
{
	static int	frame;
	static int	timer;

	if (timer > 3000)
	{
		if (frame == 0)
			add_anim_enemy(s_long, "xpm_art/enemy_left.xpm");
		else if (frame == 1)
			add_anim_enemy(s_long, "xpm_art/enemy_right.xpm");
		helper(&frame);
		timer = 0;
	}
	else
		timer++;
}
