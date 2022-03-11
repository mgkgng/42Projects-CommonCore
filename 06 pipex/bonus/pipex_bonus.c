/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgk <mgk@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:12:33 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/11 21:25:13 by mgk              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	here_doc(char *limiter)
{
	char	*line;
	char	*r;
	int		fd_tmp;

	r = NULL;
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (ft_strlen(limiter) == ft_strlen(line) - 1
			&& !ft_strncmp(limiter, line, ft_strlen(limiter)))
			break ;
		put_buf(&r, line);
		free(line);
	}
	fd_tmp = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	write(fd_tmp, r, sizeof(r));
	free(r);
}

void	pipe_define(int *fd, int fd_in, t_cmd cmds, int i)
{
	int	file;

	if (i == 0)
	{
		file = open(cmds.infile, O_RDONLY);
		if (file < 0)
		{
			perror("filename error");
			exit(0);
		}
		dup2(file, 0);
	}
	else
		dup2(fd_in, 0);
	if (cmds.cmd[i + 1])
		dup2(fd[1], 1);
	else
	{
		file = open(cmds.outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		dup2(file, 1);
	}
	close(fd[0]);
}

int	execute_loop(t_pipex pipex, int fd_in)
{
	int		fd[2];
	pid_t	pid;
	int		i;

	i = 0;
	while (pipex.cmds[i])
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			pipe_define(fd, fd_in, cmds, i);
			execve(cmds.cmd[i], cmds.args[i], path.paths);
			exit(1);
		}
		else
		{
			wait(NULL);
			close(fd[1]);
			fd_in = fd[0];
			i++;
		}
	}
	return (terminate(pipex));
}

int	terminate(t_pipex pipex)
{
	int	i;

	i = 0;
	while (pipex.cmds[i])
		free(pipex.cmds[i++]);
	free(pipex.cmds);
	unlink("here_doc");
	return (0);
}

int	ft_pipex(t_pipex pipex)
{
	return (execute_loop(pipex, STDIN_FILENO));
}