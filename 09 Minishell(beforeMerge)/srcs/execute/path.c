/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:23:42 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/15 19:05:03 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_isdir(char *s)
{
	struct stat stats;

	if (stat(s, &stats) == 0 && S_ISDIR(stats.st_mode))
	{
		ft_putstr_fd(s, 2);
		ft_putstr_fd(": is a directory\n", 2);
		exit(126);
	}
}

char	*get_pathname(char *s, char **paths)
{
	char		*cmd;
	int			i;

	check_isdir(s);
	if (access(s, F_OK) == 0)
		return (s);
	i = -1;
	while (paths[++i] && s[0] != '/')
	{
		cmd = ft_strjoin(paths[i], "/", 0);
		cmd = ft_strjoin(cmd, s, 1);
		if (access(cmd, X_OK) == 0)
			return (cmd);
		else
			free(cmd);
	}
	ft_putstr_fd(s, 2);
	if (s[0] == '/')
		ft_putstr_fd(": No such file or directory\n", 2);
	else
		ft_putstr_fd(": command not found\n", 2);
	exit(127);
}
// anormalie 1 : why does "/ls" work?

char	**get_paths(char **envp)
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

	paths = get_paths(envp);
	cmd_path = get_pathname(cmd, paths);
	return (cmd_path);
}
