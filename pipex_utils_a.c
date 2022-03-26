/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:53:48 by jhii              #+#    #+#             */
/*   Updated: 2022/03/26 15:13:05 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_malloc(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned long	count;
	unsigned char	*c;

	count = 0;
	c = s;
	while (count < n)
	{
		*c++ = 0;
		count++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, size * count);
	return (ptr);
}

int	checkfd1(char **argv)
{
	int	fd;

	fd = -1;
	if (access(argv[1], F_OK) < 0)
		ft_printf("zsh: no such file or directory: %s\n", argv[1]);
	else if (access(argv[1], R_OK) < 0)
		ft_printf("zsh: permission denied: %s\n", argv[1]);
	else
		fd = 1;
	return (fd);
}

// type[1] = infile, type[2] = outfile
int	checkfd(int argc, char **argv, int type)
{
	int	fd;

	fd = -1;
	if (type == 1)
		fd = checkfd1(argv);
	else
	{
		if (access(argv[argc - 1], F_OK) < 0)
		{
			fd = open(argv[argc - 1], O_CREAT, 0644);
			close(fd);
			fd = 1;
		}
		else if (access(argv[argc - 1], W_OK) < 0)
			ft_printf("zsh: permission denied: %s\n", argv[argc - 1]);
		else
			fd = 1;
	}
	return (fd);
}
