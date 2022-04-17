/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:39:34 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/17 20:29:31 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex parse(char **argv, char **envp)
{
    t_pipex res;
    
    res.filename[0] = argv[1];
	res.filename[1] = argv[4];
    res.arg[0] = ft_split(argv[2], ' ');
    res.arg[1] = ft_split(argv[3], ' ');
    res.paths = get_paths(envp);
    res.envp = envp;
    return (res);
}

char	*get_cmdpath(char *s, char **paths)
{
	char	*cmd;
	int		i;

    if (!access(s, F_OK))
        return (s);
	i = -1;
	while (paths[++i])
	{
		cmd = NULL;
		cmd = ft_strcat(paths[i], "/");
		cmd = ft_strcat(cmd, s);
		if (!access(cmd, F_OK))
			return (cmd);
		else
			free(cmd);
	}
	return (NULL);
}

char	**get_paths(char **envp)
{
	int		i;
	char	**res;

	i = 0;
	while (ft_strncmp(envp[i], "PATH:", 5))
		i++;
	res = ft_split(envp[i] + 5, ':');
	return (res);
}

int terminate(t_pipex pipex)
{
    // question. Do i have to free it?
    free(pipex.arg[0]);
    free(pipex.arg[1]);
    free(pipex.paths);
    return (0);
}