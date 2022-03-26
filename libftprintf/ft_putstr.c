/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:40:05 by jhii              #+#    #+#             */
/*   Updated: 2021/11/09 17:03:54 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr(char *s, int *count)
{
	unsigned long	i;

	i = 0;
	if (s == 0)
	{
		write(1, "(null)", 6);
		*count = *count + 6;
	}
	else
	{
		while (s[i] != '\0')
		{
			ft_putchar(s[i], count);
			i++;
		}
	}
}
