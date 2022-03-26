/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:42:40 by jhii              #+#    #+#             */
/*   Updated: 2021/11/09 13:26:18 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(int n, int *count)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648", count));
	else
	{
		if (n < 0)
		{
			ft_putchar('-', count);
			n = n * -1;
		}
		if (n > 9)
			ft_putnbr(n / 10, count);
		ft_putchar((n % 10) + '0', count);
	}
}
