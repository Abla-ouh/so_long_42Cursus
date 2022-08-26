/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:05:56 by abouhaga          #+#    #+#             */
/*   Updated: 2022/08/07 21:33:26 by abouhaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_wall_floor(t_tools *s_long)
{
	s_long->img = mlx_xpm_file_to_image(s_long->mlx, "xpm_art/floor.xpm",
			&s_long->x, &s_long->y);
	mlx_put_image_to_window(s_long->mlx, s_long->win, s_long->img,
		0, 0);
	mlx_destroy_image(s_long->mlx, s_long->img);
	s_long->img = mlx_xpm_file_to_image(s_long->mlx, "xpm_art/wall.xpm",
			&s_long->x, &s_long->y);
	mlx_put_image_to_window(s_long->mlx, s_long->win, s_long->img,
		0, 0);
	mlx_destroy_image(s_long->mlx, s_long->img);
}
