/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:09:40 by jhii              #+#    #+#             */
/*   Updated: 2022/03/26 15:12:50 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libftprintf/libftprintf.h"

typedef struct s_array
{
	int		proc_size;
	pid_t	*processes;
	char	*heredoc;
}	t_array;

char	**get_path(char **envp);
char	*re_path(char *str1, char *str2);
void	run_pipex(int argc, char **argv, char **envp);
void	run_heredoc(int argc, char **argv, char **envp);
void	pipex(t_array *array, int argc, char **argv, char **envp);
void	here_doc(t_array *array, int argc, char **argv);
void	printpipe(int argc);
void	run_exec(char *argv, char **envp);
void	free_malloc(char **tab);
void	mulwaitpid(t_array *array);
int		checkfd1(char **argv);
int		checkfd(int argc, char **argv, int type);
int		ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(const char *s, char c);
char	*findcmd(char **argv, int i);
int		strcompare(char *str1, char *str2);
int		ft_getnl(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(const char *s, size_t start, size_t len);
char	*get_next_line(int fd);

#endif
