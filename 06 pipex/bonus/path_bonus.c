/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:34:56 by min-kang          #+#    #+#             */
/*   Updated: 2021/12/28 17:10:49 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

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
		cmd = ft_strjoin(paths[i], "/");
		cmd = ft_strjoin_gnl(cmd, s);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		else
			free(cmd);
	}
	return (NULL);
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

t_cmd	all_commands(int argc, char **argv, t_envp path)
{
	int		i;
	int		j;
	t_cmd	result;
	int		cmd_n;

	cmd_n = argc - 2;
	i = 1;
	if (!ft_strcmp("here_doc", argv[1]))
	{
		cmd_n--;
		i++;
	}
	result.cmd = malloc((cmd_n + 1) * sizeof(char *));
	result.args = malloc(cmd_n * sizeof(char **));
	j = -1;
	while (++i < argc - 1)
	{
		result.args[++j] = ft_split(argv[i], ' ');
		result.cmd[j] = pathname_creator(result.args[j][0], path.paths);
		if (!result.cmd[j])
			ft_free(&result);
	}
	result.cmd[++j] = NULL;
	return (result);
}
