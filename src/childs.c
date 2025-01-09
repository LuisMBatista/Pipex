/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:36:35 by lumiguel          #+#    #+#             */
/*   Updated: 2025/01/09 14:02:06 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	first_cmd(t_pipex pipex, char **argv, char **env)
{
	char	*b_path;

	pipex.fd_in = open(argv[1], O_RDONLY);
	fd_in_check(pipex.fd_in);
	pipex.args = get_args(argv[2]);
	b_path = get_path(env, pipex.args[0]);
	if (!b_path)
	{
		ft_printf("Error: Command not found\n");
		free_2d_array(pipex.args);
		exit(127);
	}
	pipex.path = b_path;
	dup2(pipex.fd_in, STDIN_FILENO);
	dup2(pipex.pipe_fd[1], STDOUT_FILENO);
	close(pipex.pipe_fd[0]);
	close(pipex.pipe_fd[1]);
	close(pipex.fd_in);
	execve(pipex.path, pipex.args, env);
	perror("Error: execve failed for first command");
	free_2d_array(pipex.args);
	free(pipex.path);
	exit(1);
}

int	second_cmd(t_pipex pipex, char **argv, char **env)
{
	char	*b_path;

	pipex.fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	fd_in_check(pipex.fd);
	pipex.args = get_args(argv[3]);
	b_path = get_path(env, pipex.args[0]);
	if (b_path == NULL)
	{
		ft_printf("Error: Command not found\n");
		free_2d_array(pipex.args);
		exit(127);
	}
	pipex.path = b_path;
	dup2(pipex.pipe_fd[0], STDIN_FILENO);
	dup2(pipex.fd, STDOUT_FILENO);
	close(pipex.pipe_fd[1]);
	close(pipex.pipe_fd[0]);
	execve(pipex.path, pipex.args, env);
	perror("Error: execve failed for second command");
	free_2d_array(pipex.args);
	free(pipex.path);
	exit(1);
}
