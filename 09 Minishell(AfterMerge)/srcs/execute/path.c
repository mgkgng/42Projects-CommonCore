/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:23:42 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/22 13:54:28 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*pathname_creator(char *s, char **paths)
{
	char	*cmd;
	int		i;

	if (access(s, F_OK) == 0)
		return (s);
	i = -1;
	while (paths[++i])
	{
		cmd = ft_strjoin(paths[i], "/", 0);
		cmd = ft_strjoin(cmd, s, 1);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		else
			free(cmd);
	}
	ft_putstr_fd("Error: command not found\n", 2);
	return (NULL);
}

char	**possible_path(char **envp)
{
	int		i;
	char	**result;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	result = ft_split(envp[i], ':');
	return (result);
}

char	*path_define(char *cmd, char **envp)
{
	char	*cmd_path;
	char	**paths;

	paths = possible_path(envp);
	cmd_path = pathname_creator(cmd, paths);
	return (cmd_path);
}
