/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:27:33 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/17 20:23:09 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_proc(t_pipex pipex, int *pipe_fd, int proc)
{
	int	fd;

	fd = open(pipex.filename[proc], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(pipex.filename[proc], 2);
		ft_putendl_fd(": Cannot read file.", 2);
		exit(EXIT_FAILURE);
	}
	if (!proc)
	{
		dup2(fd, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
	}
	else
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		dup2(fd, STDOUT_FILENO);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execve(get_cmdpath(pipex.arg[proc][0], pipex.paths), pipex.arg[proc], pipex.envp);
	ft_putendl_fd("Error: execve didn't work expectedly.", 2);
	exit(EXIT_FAILURE);
}

int	ft_pipex(t_pipex pipex)
{
	int		fd[2];
	pid_t	pid;

	pipe(fd);
	pid = fork();
	if (!pid)
		pipex_proc(pipex, fd, 0);
	else
	{
		wait(NULL);
		pipex_proc(pipex, fd, 1);
	}
	return (terminate(pipex));
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
        ft_putendl_fd("Error: Wrong argument number", 2);
		exit(EXIT_FAILURE);
	}
	return (ft_pipex(parse(argv, envp)));
}
