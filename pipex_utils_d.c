/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:11:42 by jhii              #+#    #+#             */
/*   Updated: 2022/03/26 15:10:32 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*findcmd(char **argv, int i)
{
	if (strcompare(argv[1], "here_doc"))
		return (argv[i + 3]);
	else
		return (argv[i + 2]);
}

void	printpipe(int argc)
{
	int	i;

	i = -1;
	while (++i < argc - 5)
		ft_printf("pipe ");
	ft_printf("heredoc> ");
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
