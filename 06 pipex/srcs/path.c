/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:30:20 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/07 13:33:51 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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

char	**get_path(char **envp)
{
	int		i;
	char	**res;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH:", 5))
		i++;
	res = ft_split(envp[i] + 5, ':');
	return (res);
}
