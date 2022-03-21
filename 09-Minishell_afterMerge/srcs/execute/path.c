/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:23:42 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/16 15:28:19 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_isdir(char *s)
{
	struct stat	stats;

	if (stat(s, &stats) == 0 && S_ISDIR(stats.st_mode))
	{
		print_error(s, 3);
		exit(126);
	}
}

static char	*get_pathname(char *s, char **paths)
{
	char		*cmd;
	int			i;

	check_isdir(s);
	if (access(s, X_OK) == 0)
		return (s);
	i = -1;
	while (paths && paths[++i] && s[0] != '/')
	{
		cmd = ft_strjoin(paths[i], "/", 0);
		cmd = ft_strjoin(cmd, s, 1);
		if (access(cmd, X_OK) == 0)
			return (cmd);
		else
			free(cmd);
	}
	if (s[0] == '/')
		print_error(s, 1);
	else
		print_error(s, 2);
	exit(127);
}

static char	**get_paths(char **envp)
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
	char	*cmdpath;
	char	**paths;

	paths = get_paths(envp);
	cmdpath = get_pathname(cmd, paths);
	return (cmdpath);
}
