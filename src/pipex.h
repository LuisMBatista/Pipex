/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:20:27 by lumiguel          #+#    #+#             */
/*   Updated: 2025/01/09 14:15:51 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct s_pipex
{
	int		fd;
	int		pid1;
	int		pid2;
	int		pipe_fd[2];
	char	*path;
	char	**args;
	int		fd_in;
}			t_pipex;

typedef struct s_status
{
	int		status;
	int		exit_status2;
}			t_status;

char	*get_path(char **env, char *cmd);
char	**get_args(char *cmd);
void	free_2d_array(char **array);
void	argc_check(int argc);
void	pipe_check(int pipe_fd[2]);
void	pid_check(int pid);
int		first_cmd(t_pipex pipex, char **argv, char **env);
int		second_cmd(t_pipex pipex, char **argv, char **env);
void	fd_in_check(int fd);
int		path_check(char *b_path, t_pipex pipex);
char	*get_right_path(char **env, char *cmd_with_slash);
char	*try_paths(char **path, char *cmd_with_slash);

#endif
