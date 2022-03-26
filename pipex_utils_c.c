/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:58:24 by jhii              #+#    #+#             */
/*   Updated: 2022/03/24 14:01:18 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_getnl(const char *str)
{
	int		index;
	char	*temp;

	if (!str)
		return (0);
	index = 0;
	temp = (char *)str;
	while (*temp != '\n')
	{
		if (*temp == '\0')
			return (0);
		temp++;
		index++;
	}
	return (index + 1);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		nlen;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	nlen = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = (char *)malloc(nlen + 1);
	if (str == NULL)
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

char	*ft_substr(const char *s, size_t start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	slen = (size_t)ft_strlen(s);
	if (start + len > slen)
		len = slen - start;
	if (start > slen)
		len = 0;
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	while (i < len && s[start + i] != '\0')
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	mulwaitpid(t_array *array)
{
	int	i;
	int	status;

	i = 0;
	while (i < array->proc_size)
		waitpid(array->processes[i++], &status, 0);
}

int	strcompare(char *str1, char *str2)
{
	int	i;

	i = -1;
	if (ft_strlen(str1) == ft_strlen(str2))
	{
		while (str1[++i])
		{
			if (str1[i] != str2[i])
				return (0);
		}
	}
	else
		return (0);
	return (1);
}
