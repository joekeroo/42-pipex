/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:19:19 by jhii              #+#    #+#             */
/*   Updated: 2022/03/26 15:15:00 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_heredoc(int argc, char **argv, char **envp)
{
	t_array	*array;

	array = ft_calloc(1, sizeof(t_array));
	if (checkfd(argc, argv, 2) < 0)
		exit(-1);
	array->processes = ft_calloc((argc - 4), sizeof(pid_t));
	array->proc_size = argc - 4;
	array->heredoc = "\0";
	here_doc(array, argc, argv);
	pipex(array, argc, argv, envp);
	free(array->heredoc);
	free(array->processes);
	free(array);
}
