/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:39:34 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/17 20:00:43 by min-kang         ###   ########.fr       */
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

int error(int code, char *supp)
{
    if (code == 1)
        ft_putstr_fd("Error 1: Wrong argument number\n", 2);
    if (code == 2)
    {
        ft_putstr_fd(supp, 2);
        ft_putendl_fd(": Cannot read file.", 2);
    }
    if (code == 3)
        ft_putendl_fd("Error occured with execve", 2);
    exit(EXIT_FAILURE);
}

int terminate(t_pipex pipex, int *fd)
{
    free(pipex.arg[0]);
    free(pipex.arg[1]);
    free(pipex.paths);
    close(fd[0]);
    close(fd[1]);
    return (0);
}