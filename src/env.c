/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:17:49 by lumiguel          #+#    #+#             */
/*   Updated: 2024/10/31 17:43:56 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

char *get_path (char **env, char *cmd)
{
	int i;
	int j;
	char **path;

	i = 0;
	printf("cmd: %s\n", cmd);
	cmd = ft_strjoin("/", cmd);
	while(env[i]!= NULL)
	{
		if (ft_strnstr(env[i], "PATH=", 5))
		{
			path = ft_split(env[i] + 5, ':');
			j = 0;
			while (path[j] != NULL)
			{
				puts("quack");
				if (access(ft_strjoin(path[j], cmd), F_OK) == 0)
				{
					puts("quackers");
					return (ft_strjoin(path[j], cmd));
				}
				j++;
			}
		}
		i++;
	}
	perror("Error: PATH not found");
	exit(1);
}


