/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:58:56 by jhii              #+#    #+#             */
/*   Updated: 2022/03/21 17:09:10 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*re_path(char *str1, char *str2)
{
	int		i;
	int		j;
	int		len;
	char	*result;

	if (!str1 || !str2)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(str1) + ft_strlen(str2) + 1;
	result = malloc(sizeof(char) * len + 1);
	while (str1[j])
		result[i++] = str1[j++];
	result[i++] = '/';
	j = 0;
	while (str2[j])
		result[i++] = str2[j++];
	result[i] = '\0';
	return (result);
}
