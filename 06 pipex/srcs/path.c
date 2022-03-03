/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:30:20 by min-kang          #+#    #+#             */
/*   Updated: 2021/12/24 16:32:46 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*cmd_define(char *s)
{
	char	*result;
	int		i;

	i = 0;
	result = NULL;
	while (s[i] && s[i] != ' ')
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*pathname_creator(char *s, char **paths)
{
	char	*cmd;
	int		i;

	i = -1;
	while (paths[++i])
	{
		cmd = ft_strjoin_gnl(paths[i], "/");
		cmd = ft_strjoin_gnl(cmd, s);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		else
			free(cmd);
	}
	perror("Command name error");
	exit(0);
}

int	path_detector(char *s)
{
	int		i;
	char	*path;

	path = ft_strdup("PATH");
	i = -1;
	while (path[++i])
	{
		if (s[i] != path[i])
		{
			free(path);
			return (0);
		}
	}
	free(path);
	return (1);
}

char	**possible_path(char **envp)
{
	int		i;
	char	**result;

	i = 0;
	while (envp[i] && !path_detector(envp[i]))
		i++;
	result = ft_split(envp[i] + 5, ':');
	return (result);
}
