/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 09:44:14 by abouhaga          #+#    #+#             */
/*   Updated: 2021/12/07 10:40:37 by abouhaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *p_len)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", p_len);
		return ;
	}
	while (str[i])
	{
		ft_putchar(str[i], p_len);
		i++;
	}
}

void	ft_putnbr(int nbr, int *p_len)
{
	if (nbr == -2147483648)
	{
		ft_putstr("-2147483648", p_len);
		return ;
	}
	else if (nbr < 0)
	{
		ft_putchar('-', p_len);
		ft_putnbr(-nbr, p_len);
	}
	else if (nbr >= 10)
	{
		ft_putnbr(nbr / 10, p_len);
		ft_putchar(nbr % 10 + '0', p_len);
	}
	else
		ft_putchar(nbr + '0', p_len);
}

void	ft_putunbr(unsigned int nbr, int *p_len)
{
	if (nbr >= 10)
	{
		ft_putunbr(nbr / 10, p_len);
		ft_putchar(nbr % 10 + '0', p_len);
	}
	else
		ft_putchar(nbr + '0', p_len);
}

void	ft_puthex(unsigned int nbr, char c, int *p_len)
{
	char	*hex;

	hex = NULL;
	if (c == 'x')
		hex = "0123456789abcdef";
	else if (c == 'X')
		hex = "0123456789ABCDEF";
	if (nbr < 16)
		ft_putchar(hex[nbr % 16], p_len);
	if (nbr >= 16)
	{
		ft_puthex(nbr / 16, c, p_len);
		ft_putchar(hex[nbr % 16], p_len);
	}
}

void	ft_putadr(size_t address, char c, int *p_len)
{
	char	*hex;

	hex = NULL;
	if (c == 'x')
		hex = "0123456789abcdef";
	else if (c == 'X')
		hex = "0123456789ABCDEF";
	if (address < 16)
		ft_putchar(hex[address % 16], p_len);
	if (address >= 16)
	{
		ft_putadr(address / 16, c, p_len);
		ft_putchar(hex[address % 16], p_len);
	}
}
