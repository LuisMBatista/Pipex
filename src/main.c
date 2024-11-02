/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:10:58 by lumiguel          #+#    #+#             */
/*   Updated: 2024/11/02 20:01:09 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **env) 
{
	char *b_path;
	t_pipex pipex; 

	if (argc != 5) 
	{
		ft_printf("Error: Wrong number of arguments\n");
		return (1);
	}
	pipex.fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex.fd == -1) 
	{
		perror("Error opening file");
		return (1);
	}
	if (pipe(pipex.pipe_fd) == -1) 
	{
		perror("Error: pipe failed");
		return (1);
	}

															// First fork: Execute the first command
	pipex.pid = fork();
	if (pipex.pid == -1) 
	{
		perror("Error: fork failed");
		return (1);
	}
	if (pipex.pid == 0) 
	{
		pipex.args = get_args(argv[2]);
		b_path = get_path(env, pipex.args[0]);
		if (b_path == NULL) 
		{
			ft_printf("Error: Command not found\n");
			return (1);
		}
		pipex.path = b_path;

		dup2(pipex.pipe_fd[1], STDOUT_FILENO);	// Redirect stdout to pipe's write end
		close(pipex.pipe_fd[0]);				// Close unused read end
		execve(pipex.path, pipex.args, env);
		perror("Error: execve failed for first command");
		exit(1);
	}

																			/ Second fork: Execute the second command
	pipex.pid = fork();
	if (pipex.pid == -1) 
	{
		perror("Error: fork failed");
		return (1);
	}
	if (pipex.pid == 0) 
	{
		pipex.args = get_args(argv[3]);
		b_path = get_path(env, pipex.args[0]);
		if (b_path == NULL) 
		{
			ft_printf("Error: Command not found\n");
			return (1);
		}
		pipex.path = b_path;

		dup2(pipex.pipe_fd[0], STDIN_FILENO);	// Redirect stdin to pipe's read end
		dup2(pipex.fd, STDOUT_FILENO);			// Redirect stdout to output file
		close(pipex.pipe_fd[1]);				// Close unused write end
		execve(pipex.path, pipex.args, env);	// Execute second command
		perror("Error: execve failed for second command");
		exit(1);
	}
	close(pipex.pipe_fd[0]);
	close(pipex.pipe_fd[1]);
	close(pipex.fd);

	waitpid(-1, NULL, 0);
	waitpid(-1, NULL, 0);

	return (0);
}
