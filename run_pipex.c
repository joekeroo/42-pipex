/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:18:52 by jhii              #+#    #+#             */
/*   Updated: 2022/03/26 14:50:06 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_pipex(int argc, char **argv, char **envp)
{
	t_array	*array;

	array = ft_calloc(1, sizeof(t_array));
	if (checkfd(argc, argv, 2) < 0 || checkfd(argc, argv, 1) < 0)
		exit(-1);
	array->processes = ft_calloc((argc - 3), sizeof(pid_t));
	array->proc_size = argc - 3;
	pipex(array, argc, argv, envp);
	free(array->processes);
	free(array);
}
