/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:39:02 by abouhaga          #+#    #+#             */
/*   Updated: 2022/08/07 23:22:46 by abouhaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	sprite_position(t_tools *s_long, char c)
{
	int	i;
	int	j;

	i = 0;
	while (s_long->map[i])
	{
		j = 0;
		while (s_long->map[i][j])
		{
			if (s_long->map[i][j] == 'P')
			{
				if (c == 'y')
					return (i);
				else if (c == 'x')
					return (j);
			}
			j++;
		}
		i++;
	}
	return (s_long->collectible);
}

int	dimensions(char **lines, char c)
{
	int	cnt;

	cnt = 0;
	if (c == 'w')
	{
		while (lines[0][cnt] != '\0')
			cnt++;
	}
	else
	{
		while (lines[cnt])
			cnt++;
	}
	return (cnt);
}

void	fill_floor(t_tools s_long)
{
	int	i;
	int	j;

	i = 0;
	while (i < s_long.map_width)
	{
		j = 0;
		while (j < s_long.map_height)
		{
			mlx_put_image_to_window(s_long.mlx, s_long.win,
				s_long.img, i * 46, j * 46);
				j++;
		}
		i++;
	}
}

int	position_check(t_tools *s_long, int y, int x)
{
	if (s_long->map[y][x] == 'E' && s_long->collectible == 0)
		exit (1);
	if (s_long->map[y][x] == 'C')
	{
		s_long->map[y][x] = '0';
		s_long->collectible--;
	}
	if (s_long->map[y][x] == '1')
		return (0);
	if (s_long->map[y][x] == 'E' && s_long->collectible != 0)
		return (0);
	if (s_long->map[y][x] == 'G')
		exit (1);
	return (1);
}

void	open_door(t_tools *s_long)
{
	int	i;
	int	j;

	i = 0;
	if (s_long->collectible == 0)
	{	
		while (s_long->map[i])
		{
			j = 0;
			while (s_long->map[i][j])
			{
				if (s_long->map[i][j] == 'E')
				{
					s_long->img = mlx_xpm_file_to_image(s_long->mlx,
							"xpm_art/dooropen.xpm", &s_long->x, &s_long->y);
					mlx_put_image_to_window(s_long->mlx, s_long->win,
						s_long->img, j * 46, i * 46);
					mlx_destroy_image(s_long->mlx, s_long->img);
				}
				j++;
			}
			i++;
		}	
	}
}
