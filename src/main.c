/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:10:58 by lumiguel          #+#    #+#             */
/*   Updated: 2024/10/31 13:23:07 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

int main(int argc, char **argv, char **env) 
{
	char *b_path;
	t_pipex	*pipex;
	char *args[] = {"cat", argv[1], NULL};

	pipex = malloc(sizeof(t_pipex));
	
	if (argv == NULL)
	{
		ft_printf("Error: Wrong number of argumexnts\n");
		return (1);
	}
	if (argc != 2)
	{
		ft_printf("Error: Wrong number of arguments\n");
		return (1);
	}
	b_path = get_path(env, "/cat");
	pipex->path = b_path;
	printf("path: %s\n", pipex->path);
	
if (execve(pipex->path, args, NULL) == -1) 
    {
        perror("execve failed");
        free(pipex->path);
        free(pipex);
        return (1);
    }
    free(pipex->path);
    free(pipex);
    return (0);
	return (0);
}

