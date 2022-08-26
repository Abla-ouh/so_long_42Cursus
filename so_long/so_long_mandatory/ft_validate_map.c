/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:46:02 by abouhaga          #+#    #+#             */
/*   Updated: 2022/08/12 14:23:30 by abouhaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	validate_extension(char *av)
{
	int	lenght;

	lenght = ft_strlen(av) - 4;
	if (ft_strcmp(&av[lenght], ".ber"))
		ft_error('e');
}

void	validate_lines(char *str)
{
	int	i;
	int	player;

	i = 0;
	player = 0;
	if (str[i] == '\n')
		ft_error('w');
	while (str[i])
	{
		if (str[i] == 'P')
			player++;
		if ((str[i] == '\n' && str[i + 1] == '\n')
			|| str[ft_strlen(str) - 1] == '\n')
			ft_error('w');
		i++;
	}
	if (player > 1 || player == 0)
		ft_error('p');
}

int	validate_components(char **lines, int lenght)
{
	int	i;
	int	j;

	i = -1;
	while (lines[++i])
	{
		if (ft_strlen(lines[i]) < 3 || (int)ft_strlen(lines[i]) != lenght)
			ft_error('m');
		j = -1;
		while (lines[i][++j])
		{
			if (lines[i][j] != '0' && lines[i][j] != '1'
				&& lines[i][j] != 'P' && lines[i][j] != 'C'
				&& lines[i][j] != 'E')
				ft_error('n');
		}
	}
	return (1);
}

int	validate_walls(char **lines, int lenght)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = -1;
	k = 1;
	while (lines[++i])
	{
		if (lines[i][0] != '1' || lines[i][lenght - 1] != '1')
			k = 0;
	}
	i--;
	while (lines[i][++j])
	{
		if (lines[i][j] != '1' || lines[0][j] != '1')
			k = 0;
	}
	if (k == 0)
		ft_error('k');
	return (1);
}

char	**validate_map(char *av)
{
	char	*line;
	int		fd;
	char	**lines;

	line = NULL;
	validate_extension(av);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_error ('n');
	line = read_file(fd);
	validate_lines(line);
	lines = ft_split(line, '\n');
	free(line);
	validate_components(lines, (int)ft_strlen(lines[0]));
	validate_walls(lines, (int)ft_strlen(lines[0]));
	return (lines);
}
