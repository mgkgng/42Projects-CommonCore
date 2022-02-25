/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:12:33 by min-kang          #+#    #+#             */
/*   Updated: 2021/12/26 19:21:58 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	here_doc(char *limiter)
{
	char	*w_line;
	char	*r_data;
	int		fd_tmp;

	r_data = NULL;
	while (1)
	{
		w_line = get_next_line(STDIN_FILENO);
		if (ft_strlen(limiter) == ft_strlen(w_line) - 1
			&& !ft_strncmp(limiter, w_line, ft_strlen(limiter)))
			break ;
		r_data = ft_strjoin_gnl(r_data, w_line);
		free(w_line);
	}
	fd_tmp = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	write(fd_tmp, r_data, ft_strlen(r_data));
	free(r_data);
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

void	pipe_loop(t_cmd cmds, t_envp path)
{
	int		fd[2];
	pid_t	pid;
	int		fd_in;
	int		i;

	fd_in = 0;
	i = 0;
	while (cmds.cmd[i])
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			pipe_define(fd, fd_in, cmds, i);
			execve(cmds.cmd[i], cmds.args[i], path.paths);
			exit(0);
		}
		else
		{
			wait(NULL);
			close(fd[1]);
			fd_in = fd[0];
			i++;
		}
	}
}
