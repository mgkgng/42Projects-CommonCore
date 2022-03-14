/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:23:42 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/14 12:23:12 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*pathname_creator(char *s, char **paths)
{
	char		*cmd;
	struct stat stats;
	int			i;

	if (stat(s, &stats) == 0 && S_ISDIR(stats.st_mode))
	{
		ft_putstr_fd(s, 2);
		ft_putstr_fd(": is a directory\n", 2);
		exit(126);
	}
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
	ft_putstr_fd(s, 2);
	if (s[0] == '/')
		ft_putstr_fd(": No such file or directory\n", 2);
	else
		ft_putstr_fd(": command not found\n", 2);
	exit(127);
}
// anormalie 1 : why does "/ls" work?

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
