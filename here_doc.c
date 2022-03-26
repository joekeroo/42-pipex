/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:47:32 by jhii              #+#    #+#             */
/*   Updated: 2022/03/24 16:49:02 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// argv[2] = LIMITER
void	here_doc(t_array *array, int argc, char **argv)
{
	char	*temp;
	char	*temp1;
	char	*temp2;

	temp = ft_strjoin(argv[2], "\n");
	while (1)
	{
		printpipe(argc);
		temp1 = get_next_line(0);
		temp2 = array->heredoc;
		if (strcompare(temp1, temp))
		{
			free(temp1);
			break ;
		}
		if (array->heredoc[0] != '\0')
			free(array->heredoc);
		array->heredoc = ft_strjoin(temp2, temp1);
		free(temp1);
	}
	free(temp);
}
