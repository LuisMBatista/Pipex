/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:20:27 by lumiguel          #+#    #+#             */
/*   Updated: 2024/11/06 20:01:13 by lumiguel         ###   ########.fr       */
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
	int 	pid2;
	int		pipe_fd[2];
	char	*path;
	char	**args;
	int		fd_in;
} 			t_pipex;

char *get_path (char **env, char *cmd);
char **get_args(char *cmd);
void free_2d_array(char **array);
void argc_check(int argc);
void pipe_check(int pipe_fd[2]);
void pid_check(int pid);
int first_cmd(t_pipex pipex, char ** argv, char **env);
int second_cmd(t_pipex pipex, char ** argv, char **env);
void fd_in_check(int fd);
int path_check(char *b_path, t_pipex pipex);
char *get_right_path(char **env, char *cmd_with_slash);
char *try_paths(char **path, char *cmd_with_slash);

#endif
