/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:27:33 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/03 01:58:54 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_pipex(t_pipex pipex, int *fd)
{
	char	**args;
	char	*cmdpath;
	int		in;

	in = open(pipex.in, O_RDONLY);
	if (in < 0) {
		ft_putstr_fd(pipex.in, 2);
		ft_putstr_fd(": Cannot read file.\n", 2);
		exit(EXIT_FAILURE);
	}
	dup2(in, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	args = ft_split(pipex.cmd1, ' ');
	cmdpath = get_cmdpath(args[0], pipex.paths);
	execve(cmdpath, args, pipex.envp);
	ft_putstr_fd("Error 7: exec failed in child process.\n", 2);
	exit(7);
}

void	parent_pipex(t_pipex pipex, int *fd)
{
	char	**args;
	char	*cmdpath;
	int		out;

	out = open(pipex.out, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	dup2(fd[0], STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	args = ft_split(pipex.cmd2, ' ');
	cmdpath = get_cmdpath(args[0], pipex.paths);
	execve(cmdpath, args, pipex.envp);
	ft_putstr_fd("Error: exec failed in parent process.\n", 2);
	exit(8);
}

int	ft_pipex(t_pipex pipex)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		return (error(2));
	pid = fork();
	if (pid < 0)
		return (error(3));
	if (pid == 0)
		child_pipex(pipex, fd);
	else
	{
		wait(NULL);
		parent_pipex(pipex, fd);
	}
	return (terminate(pipex));
}
