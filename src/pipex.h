/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:20:27 by lumiguel          #+#    #+#             */
/*   Updated: 2024/10/31 19:24:49 by lumiguel         ###   ########.fr       */
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
	int		pid;
	int		pipe_fd[2];
	char	*path;
	char	**args;
} 			t_pipex;

char *get_path (char **env, char *cmd);
char **get_args(char *cmd);

#endif
