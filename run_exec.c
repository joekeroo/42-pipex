/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:30:27 by jhii              #+#    #+#             */
/*   Updated: 2022/03/23 14:01:48 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Executes on success, returns -1 on failure.
void	run_exec(char *argv, char **envp)
{
	int		i;
	int		j;
	char	**cmds;
	char	**paths;
	char	*new_path;

	i = 0;
	paths = get_path(envp);
	cmds = ft_split(argv, ' ');
	while (paths[i])
	{
		j = 0;
		while (cmds[j])
		{
			new_path = re_path(paths[i], cmds[j]);
			execve(new_path, cmds, envp);
			free(new_path);
			j++;
		}
		i++;
	}
	dup2(2, 1);
	ft_printf("zsh: command not found: %s\n", cmds[0]);
}
