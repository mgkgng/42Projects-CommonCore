/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:27:33 by min-kang          #+#    #+#             */
/*   Updated: 2021/12/24 16:29:26 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_pipex(char *cmd, char *input, t_envp path, int *fd)
{
	int		file;
	char	**args;
	char	*cmd_path;

	file = open(input, O_RDONLY);
	if (file == -1)
	{
		perror("file name error");
		exit(0);
	}
	dup2(file, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	args = ft_split(cmd, ' ');
	cmd_path = pathname_creator(args[0], path.paths);
	execve(cmd_path, args, path.envp);
	exit(EXIT_FAILURE);
}

void	parent_pipex(char *cmd, char *output, t_envp path, int *fd)
{
	int		file;
	char	**args;
	char	*cmd_path;

	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	args = ft_split(cmd, ' ');
	file = open(output, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	dup2(file, STDOUT_FILENO);
	cmd_path = pathname_creator(args[0], path.paths);
	execve(cmd_path, args, path.envp);
	exit(EXIT_FAILURE);
}

void	ft_pipex(char **argv, t_envp path)
{
	int		fd[2];
	pid_t	pid;

	pipe(fd);
	pid = fork();
	if (pid == 0)
		child_pipex(argv[2], argv[1], path, fd);
	else
	{
		wait(NULL);
		parent_pipex(argv[3], argv[4], path, fd);
	}
}
