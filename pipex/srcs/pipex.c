/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:27:33 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/17 19:59:46 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_proc(t_pipex pipex, int *pipe_fd, int proc)
{
	int	fd;

	fd = open(pipex.filename[proc], O_RDONLY);
	if (fd < 0)
		error(2, pipex.filename[proc]);
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
	error(3, NULL);
}

int	pipex(t_pipex pipex)
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
	t_pipex	pipex;

	if (argc != 5)
		return (error(1, NULL));
	return (pipex(parse(argv, envp)));
}
