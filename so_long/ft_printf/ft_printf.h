/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:54:27 by abouhaga          #+#    #+#             */
/*   Updated: 2021/12/07 11:12:53 by abouhaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, int *p_len);
void	ft_putstr(char *str, int *p_len);
void	ft_putnbr(int nbr, int *p_len);
void	ft_putunbr(unsigned int nbr, int *p_len);
void	ft_puthex(unsigned int nbr, char c, int *p_len);
void	ft_putadr(size_t address, char c, int *p_len);

#endif
