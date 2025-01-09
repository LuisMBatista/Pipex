/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:12:59 by lumiguel          #+#    #+#             */
/*   Updated: 2025/01/09 14:15:23 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fd_in_check(int fd)
{
	if (fd == -1)
	{
		perror("Error opening file");
		exit(1);
	}
}

int	path_check(char *b_path, t_pipex pipex)
{
	if (b_path == NULL)
	{
		perror("Error: Command not found\n");
		free_2d_array(pipex.args);
		exit (127);
	}
	return (0);
}
