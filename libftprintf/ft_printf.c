/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:54:13 by jhii              #+#    #+#             */
/*   Updated: 2021/11/09 16:32:27 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_check(va_list valist, char c, int *count)
{
	if (c == 's')
		ft_putstr(va_arg(valist, char *), count);
	else if (c == 'c')
		ft_putchar(va_arg(valist, int), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(valist, int), count);
	else if (c == 'u')
		ft_putuint(va_arg(valist, unsigned int), count);
	else if (c == 'x')
		ft_puthexa(va_arg(valist, unsigned int), 1, count);
	else if (c == 'X')
		ft_puthexa(va_arg(valist, unsigned int), 2, count);
	else if (c == 'p')
	{
		ft_putstr("0x", count);
		ft_putvoid(va_arg(valist, size_t), count);
	}
	else
		ft_putchar(c, count);
}

int	ft_printf(const char *format, ...)
{
	va_list	valist;
	int		index;
	int		count;

	index = 0;
	count = 0;
	va_start(valist, format);
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			index++;
			ft_check(valist, format[index], &count);
		}
		else
			ft_putchar(format[index], &count);
		index++;
	}
	va_end(valist);
	return (count);
}
