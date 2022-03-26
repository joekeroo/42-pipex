/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:47:35 by jhii              #+#    #+#             */
/*   Updated: 2021/11/09 13:26:34 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putvoid(size_t n, int *count)
{
	size_t	remainder;

	remainder = n % 16;
	if (n > 15)
	{
		ft_putvoid(n / 16, count);
		remainder = n % 16;
	}
	if (remainder < 10)
		ft_putchar(remainder + '0', count);
	else
		ft_putchar(remainder + 'W', count);
}
