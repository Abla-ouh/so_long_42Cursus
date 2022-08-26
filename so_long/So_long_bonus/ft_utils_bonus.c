/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:30:01 by abouhaga          #+#    #+#             */
/*   Updated: 2022/08/08 14:46:59 by abouhaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(char c)
{
	if (c == 'a')
		ft_printf("Arguments not valid !");
	else if (c == 'e')
		ft_printf("The file doesn't end with \".ber\" extension !");
	else if (c == 'n')
		ft_printf("wrong data entry !");
	else if (c == 'w')
		ft_printf("Map not valid !");
	else if (c == 'p')
		ft_printf("More than one player in map or no player !");
	else if (c == 'm')
		ft_printf("Map lenght not valid !");
	else if (c == 'n')
		ft_printf("Map components not valid !");
	else if (c == 'k')
		ft_printf("Map walls not valid !");
	else if (c == 'c')
		ft_printf("No collectible to pick !");
	else if (c == 'x')
		ft_printf("nO EXIT , you will be stuck inside dude !!");
	exit(1);
}

char	*read_file(int fd)
{
	char	*str;
	char	*line;
	char	*temp;

	line = ft_strdup("");
	str = get_next_line(fd);
	while (str)
	{
		temp = line;
		line = ft_strjoin(temp, str);
		free(str);
		free(temp);
		str = get_next_line(fd);
	}
	return (line);
}

void	put_brick(t_tools *s_long, int x, int y)
{
	s_long->img = mlx_xpm_file_to_image(s_long->mlx, "xpm_art/wall.xpm",
			&s_long->x, &s_long->y);
	mlx_put_image_to_window(s_long->mlx, s_long->win, s_long->img,
		x * 46, y * 46);
	mlx_destroy_image(s_long->mlx, s_long->img);
}

void	add_brick(t_tools *s_long)
{
	int	x;
	int	y;

	y = 0;
	while (s_long->map[y])
	{
		x = 0;
		while (s_long->map[y][x])
		{
			if (x < 2 && (y == 1 || y == 0))
			{
				x++;
				continue ;
			}
			if (s_long->map[y][x] == '1')
				put_brick(s_long, x, y);
			x++;
		}
		y++;
	}
}

void	add_counter(int key, t_tools *s_long)
{
	int		i;
	char	*str;

	if (key == 2 || key == 0 || key == 1 || key == 13)
	{
		str = ft_itoa(s_long->counter);
		s_long->img = mlx_xpm_file_to_image(s_long->mlx, "xpm_art/wall.xpm",
				&s_long->x, &s_long->y);
		mlx_put_image_to_window(s_long->mlx, s_long->win, s_long->img,
			1 * 46, (-10) * 46);
		i = 0;
		while (i < s_long->map_height)
		{
			mlx_put_image_to_window(s_long->mlx, s_long->win, s_long->img,
				0, (i - 1) * 46);
			i++;
		}
		put_wall_floor(s_long);
		mlx_string_put(s_long->mlx, s_long->win, 0, 0, 0xFE0000, str);
		free(str);
	}
}
