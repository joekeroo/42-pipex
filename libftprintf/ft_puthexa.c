/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:51:44 by jhii              #+#    #+#             */
/*   Updated: 2021/11/09 13:58:34 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_puthexa(unsigned int n, unsigned int type, int *count)
{
	unsigned int	remainder;

	remainder = n % 16;
	if (n > 15)
	{
		ft_puthexa(n / 16, type, count);
		remainder = n % 16;
	}
	if (remainder < 10)
		ft_putchar(remainder + '0', count);
	else
	{
		if (type == 1)
			ft_putchar(remainder + 'W', count);
		else
			ft_putchar(remainder + '7', count);
	}
}
