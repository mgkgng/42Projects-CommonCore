/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:12:33 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/20 12:59:58 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	heredoc(char *limiter)
{
	char	*line;
	char	*r;
	int		fd;

	r = NULL;
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (ft_strlen(limiter) == ft_strlen(line) - 1
			&& !ft_strncmp(limiter, line, ft_strlen(limiter)))
			break ;
		ft_strcat(r, line);
		free(line);
	}
	fd = open("heredoc", O_CREAT | O_WRONLY | O_APPEND, 0644);
	write(fd, r, sizeof(r));
	free(r);
	return (fd);
}

int	terminate(t_pipex pipex)
{
	int	i;

	i = -1;
	while (pipex.args[++i])
		free(pipex.args[i]);
	free(pipex.paths);
	unlink("heredoc");
	return (0);
}

void	pipex_in_loop(t_pipex pipex, int *fd, int i)
{
	if (!i)
		fd[0] = pipex.in;
	if (i == pipex.size - 1)
		fd[1] = pipex.out;
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	execve(pipex.cmdpaths[i], pipex.args[i], pipex.envp);
	exit(1);
}

int	ft_pipex(t_pipex pipex)
{
	int		fd[2];
	pid_t	pid;
	int		i;

	i = -1;
	while (++i < pipex.size)
	{
		pipe(fd);
		pid = fork();
		if (!pid)
			pipex_in_loop(pipex, fd, i);
		else
		{
			wait(NULL);
			close(fd[0]);
			close(fd[1]);
		}
	}
	return (terminate(pipex));
}
