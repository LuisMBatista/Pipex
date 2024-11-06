/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:52:20 by lumiguel          #+#    #+#             */
/*   Updated: 2024/11/06 20:10:39 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

char **get_args(char *cmd)
{
	char **args = NULL;
	if (cmd == NULL || cmd[0] == '\0')
	{
		perror("Error: cmd empty");
		exit(1);
	}	
	else
		args = ft_split(cmd, ' ');
	return (args);
}

void argc_check(int argc)
{
	if (argc != 5)
	{
		dprintf(2, "Error: Wrong number of arguments\n");
		exit(1);
	}
}

void pipe_check(int pipe_fd[2])
{
	if (pipe(pipe_fd) == -1)
	{
		perror("Error: pipe failed");
		exit(1);
	}
}
void pid_check(int pid)
{
	if (pid == -1) 
	{
		perror("Error: fork failed");
		exit(1);
	}
}
