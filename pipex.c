/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:22:34 by jhii              #+#    #+#             */
/*   Updated: 2022/03/26 15:16:26 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	void	startprocess(t_array *array, int *fd, char **argv, char **envp)
{
	int	file;
	int	tmp;

	if (strcompare(argv[1], "here_doc"))
	{
		tmp = open("temp", O_CREAT | O_RDWR | O_TRUNC, 0644);
		ft_putstr_fd(array->heredoc, tmp);
		close(tmp);
		file = open("temp", O_RDONLY);
		unlink("temp");
	}
	else
		file = open(argv[1], O_RDONLY);
	dup2(file, 0);
	close(file);
	dup2(fd[1], 1);
	close(fd[1]);
	close(fd[0]);
	if (strcompare(argv[1], "here_doc"))
		run_exec(argv[3], envp);
	else
		run_exec(argv[2], envp);
	exit(1);
}

static	void	midprocess(int lastfd, int *fd, char *cmd, char **envp)
{
	dup2(lastfd, 0);
	close(lastfd);
	dup2(fd[1], 1);
	close(fd[1]);
	run_exec(cmd, envp);
	exit(1);
}

static	void	endprocess(int lastfd, int argc, char **argv, char **envp)
{
	int	file;

	if (strcompare(argv[1], "here_doc"))
		file = open(argv[argc - 1], O_WRONLY | O_APPEND, 0644);
	else
		file = open(argv[argc - 1], O_WRONLY | O_TRUNC, 0644);
	dup2(lastfd, 0);
	close(lastfd);
	dup2(file, 1);
	close(file);
	run_exec(argv[argc - 2], envp);
	exit(1);
}

static	void	closefds(int *lastfd, int *fd, int i, int size)
{
	if (i == 0)
	{
		close(fd[1]);
		*lastfd = fd[0];
	}
	else if (i == size - 1)
		close(*lastfd);
	else
	{
		close(*lastfd);
		close(fd[1]);
		*lastfd = fd[0];
	}
}

void	pipex(t_array *array, int argc, char **argv, char **envp)
{
	int		i;
	int		lastfd;
	int		fd[2];

	i = 0;
	lastfd = 0;
	while (i < array->proc_size)
	{
		if (i != array->proc_size - 1)
			pipe(fd);
		array->processes[i] = fork();
		if (array->processes[i] < 0)
			return (perror("Fork Error"));
		if (array->processes[i] == 0)
		{
			if (i == 0)
				startprocess(array, fd, argv, envp);
			else if (i == array->proc_size - 1)
				endprocess(lastfd, argc, argv, envp);
			else
				midprocess(lastfd, fd, findcmd(argv, i), envp);
		}
		closefds(&lastfd, fd, i++, array->proc_size);
	}
	mulwaitpid(array);
}
