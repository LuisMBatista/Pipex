/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:10:58 by lumiguel          #+#    #+#             */
/*   Updated: 2024/11/07 13:40:40 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex		pipex;
	t_status	status;
	int			pid;

	pid = 0;
	status.status = 0;
	argc_check(argc);
	pipe_check(pipex.pipe_fd);
	pipex.pid1 = fork();
	pid_check(pipex.pid1);
	if (pipex.pid1 == 0)
		status.status = first_cmd(pipex, argv, env);
	pipex.pid2 = fork();
	pid_check(pid);
	if (pipex.pid2 == 0)
		status.status = second_cmd(pipex, argv, env);
	else
	{
		close(pipex.pipe_fd[1]);
		close(pipex.pipe_fd[0]);
		waitpid(pipex.pid1, &status.status, 0);
		waitpid(pipex.pid2, &status.status, 0);
		status.exit_status2 = WEXITSTATUS(status.status);
		exit(status.exit_status2);
	}
}
