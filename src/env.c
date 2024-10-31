/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:17:49 by lumiguel          #+#    #+#             */
/*   Updated: 2024/10/31 13:28:53 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

char *get_path (char **env, char *cmd)
{
	int i;
	char **path;

	i = 0;
	while(env[i]!= NULL)
	{
		if (ft_strnstr(env[i], "PATH=", 5))
		{
			path = ft_split(env[i] + 5, ':');
			i = 0;
			while (path[i] != NULL)
			{
				if (access(ft_strjoin(path[i], cmd), F_OK) == 0)
					return (ft_strjoin(path[i], cmd));
				i++;
			}
		}
		i++;
	}
	perror("Error: PATH not found");
	exit(1);
}


