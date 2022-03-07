/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:34:56 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/07 21:07:40 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

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

char	**possible_path(char **envp)
{
	int		i;
	char	**res;

	i = 0;
	while (envp[i] && !path_detector(envp[i]))
		i++;
	res = ft_split(envp[i] + 5, ':');
	return (res);
}

t_cmd	all_commands(int argc, char **argv, t_envp path)
{
	int		i;
	int		j;
	t_cmd	res;
	int		cmd_n;

	cmd_n = argc - 2;
	i = 1;
	if (!ft_strcmp("here_doc", argv[1]))
	{
		cmd_n--;
		i++;
	}
	res.cmd = malloc((cmd_n + 1) * sizeof(char *));
	res.args = malloc(cmd_n * sizeof(char **));
	j = -1;
	while (++i < argc - 1)
	{
		res.args[++j] = ft_split(argv[i], ' ');
		res.cmd[j] = pathname_creator(res.args[j][0], path.paths);
		if (!res.cmd[j])
			ft_free(&res);
	}
	res.cmd[++j] = NULL;
	return (res);
}
