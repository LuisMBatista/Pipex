/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:12:59 by lumiguel          #+#    #+#             */
/*   Updated: 2024/11/07 13:52:24 by lumiguel         ###   ########.fr       */
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
		dprintf(2, "Error: Command not found\n");
		free_2d_array(pipex.args);
		exit (127);
	}
	return (0);
}
