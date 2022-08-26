/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:45:57 by abouhaga          #+#    #+#             */
/*   Updated: 2022/08/12 14:20:37 by abouhaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	t_tools	s_long;

	s_long.map = NULL;
	if (ac != 2)
		ft_error('a');
	s_long.map = validate_map(av[1]);
	lunch_game(s_long);
}
