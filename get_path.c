/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:54:54 by jhii              #+#    #+#             */
/*   Updated: 2022/03/21 13:51:06 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	char	*get_line(char **envp)
{
	int	i;
	int	j;

	i = 0;
	while (envp[i])
	{
		j = 0;
		if (envp[i][0] == 'P')
			if (envp[i][1] == 'A')
				if (envp[i][2] == 'T')
					if (envp[i][3] == 'H')
						return (envp[i]);
		i++;
	}
	return ("\0");
}

static	char	*trim_path(char	*str)
{
	int		i;
	int		j;
	char	*temp;

	i = 5;
	j = 0;
	temp = malloc(sizeof(char) * (ft_strlen(str) - i) + 1);
	while (str[i])
		temp[j++] = str[i++];
	temp[j] = '\0';
	return (temp);
}

char	**get_path(char **envp)
{
	char	*path;
	char	*trimmed;
	char	**temp;

	path = get_line(envp);
	if (path[0] == '\0')
		return (NULL);
	trimmed = trim_path(path);
	temp = ft_split(trimmed, ':');
	free(trimmed);
	return (temp);
}
