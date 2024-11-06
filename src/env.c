/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:17:49 by lumiguel          #+#    #+#             */
/*   Updated: 2024/11/06 20:23:27 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

void free_2d_array(char **array) 
{
	int i = 0;

	if (array == NULL) 
		return;
	while (array[i] != NULL) 
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	*get_path(char **env, char *cmd)
{
	char	*cmd_with_slash;
	char	*final_path;

	if (cmd == NULL)
	{
		perror("Error: cmd empty");
		exit(1);
	}
	cmd_with_slash = ft_strjoin("/", cmd);
	final_path = get_right_path(env, cmd_with_slash);
	free(cmd_with_slash);
	if (final_path != NULL)
		return (final_path);;
	return(NULL);
}

char	*get_right_path(char **env, char *cmd_with_slash)
{
	int		i;
	char	**path;
	char	*full_path;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strnstr(env[i], "PATH=", 5))
		{
			path = ft_split(env[i] + 5, ':');
			full_path = try_paths(path, cmd_with_slash);
			free_2d_array(path);
			return (full_path);
		}
		i++;
	}
	return (NULL);
}

char	*try_paths(char **path, char *cmd_with_slash)
{
	int		j;
	char	*potential_path;

	j = 0;
	while (path[j] != NULL)
	{
		potential_path = ft_strjoin(path[j], cmd_with_slash);
		if (access(potential_path, F_OK) == 0)
			return (potential_path); // Found, return allocated path
		free(potential_path); // Free unsuccessful path
		j++;
	}
	return (NULL);
}
