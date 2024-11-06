/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:10:58 by lumiguel          #+#    #+#             */
/*   Updated: 2024/11/06 17:19:39 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **env) 
{
	int STATUS;
	t_pipex pipex;

	STATUS = 0;
	argc_check(argc);
	pipe_check(pipex.pipe_fd);
	pipex.pid1 = fork();
	pid_check(pipex.pid1);
	if (pipex.pid1 == 0) 
		STATUS = first_cmd(pipex,argv,env);
	pipex.pid2 = fork();
	void pid_check(int pid);
	if (pipex.pid2 == 0) 
		STATUS = second_cmd(pipex,argv,env);
	else
	{
		close(pipex.pipe_fd[1]);
		close(pipex.pipe_fd[0]);
		waitpid(pipex.pid1, &STATUS, 0);
		waitpid(pipex.pid2, &STATUS, 0);
		int exit_status2 = WEXITSTATUS(STATUS); // Get the exit status of the second command
		exit(exit_status2);
	}
}
