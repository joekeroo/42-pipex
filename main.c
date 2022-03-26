/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:25:26 by jhii              #+#    #+#             */
/*   Updated: 2022/03/26 15:19:56 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Check for leaks, system("leaks pipex");
// lsof | grep deleted, kill -9 pid
int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
		return (0);
	if (argc == 5 && strcompare(argv[1], "here_doc"))
		return (0);
	if (strcompare(argv[1], "here_doc"))
		run_heredoc(argc, argv, envp);
	else
		run_pipex(argc, argv, envp);
	return (0);
}
