/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:39:34 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/17 19:42:34 by min-kang         ###   ########.fr       */
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

int error(int code, char *s)
{
    if (code == 1)
        ft_putstr_fd("Error 1: Wrong argument number\n", 2);
    if (code == 2)
    {
        ft_putstr_fd(s, 2);
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