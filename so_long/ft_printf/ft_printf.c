/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:32:23 by abouhaga          #+#    #+#             */
/*   Updated: 2021/12/07 11:37:59 by abouhaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *p_len)
{
	write(1, &c, 1);
	*p_len += 1;
}

static void	ft_checker(va_list ptr, char c, int *p_len)
{
	if (c == 'c')
		ft_putchar(va_arg(ptr, int), p_len);
	else if (c == 's')
		ft_putstr(va_arg(ptr, char *), p_len);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ptr, int), p_len);
	else if (c == 'u')
		ft_putunbr(va_arg(ptr, unsigned int), p_len);
	else if (c == 'x' || c == 'X')
		ft_puthex(va_arg(ptr, unsigned int), c, p_len);
	else if (c == 'p')
	{
		ft_putstr("0x", p_len);
		ft_putadr(va_arg(ptr, size_t), 'x', p_len);
	}
	else
		ft_putchar(c, p_len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ptr;
	int		lenght;

	i = 0;
	lenght = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_checker(ptr, str[++i], &lenght);
			i++;
		}
		else
			ft_putchar(str[i++], &lenght);
	}
	va_end(ptr);
	return (lenght);
}

// #include <stdio.h>
// int main()
// {
// 	int	i = 10;
// 	printf("%d", ft_printf("%cl", 'l'));
// 	//printf("%");
// }
