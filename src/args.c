/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:52:20 by lumiguel          #+#    #+#             */
/*   Updated: 2024/10/31 17:13:32 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

char **get_args(char *cmd)
{
	char **args;

	args = ft_split(cmd, ' ');
	return (args);
}