/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:54:12 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/15 16:07:22 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	cmd_execute(t_node *node, int fd_in, int fd_out, char **envp)
{
	t_redir	redir;
	char	*cmd_path;

	redir = redir_initialize(fd_in, fd_out);
	if (node->right)
		redir_define(&redir, node->right->redir_name, node->right->redir_type);
	dup2(redir.input, 0);
	dup2(redir.output, 1);
	cmd_path = path_define(node->left->args[0], envp);
	execve(cmd_path, node->left->args, envp);
	write(fd_out, "", 1);
	exit (127);
}

int	proc_child(t_node *node, char **envp, int fd_in, int *fd)
{
	close(fd[0]);
	if (node->right && node->right->node_type > 1)
		cmd_execute(node->left, fd_in, fd[1], envp);
	else
		cmd_execute(node, fd_in, 1, envp);
	return (1);
}

int	proc_parent(t_node *node, char **envp, int *fd, pid_t pid)
{
	int	res;
	int	res_child;

	close(fd[1]);
	res = execute_loop(node->right, envp, fd[0]);
	close(fd[0]);
	waitpid(pid, &res_child, 0);
	res_child = WEXITSTATUS(res_child);
	if (node->right && node->right->node_type > 1)
		return (res);
	return (res_child);
}

int	execute_loop(t_node *node, char **envp, int fd_in)
{
	int		fd[2];
	pid_t	pid;
	int		res;

	res = 0;
	if (node && node->node_type > 1)
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
			proc_child(node, envp, fd_in, fd);
		else
			res = proc_parent(node, envp, fd, pid);
	}
	return (res);
}

int	parse_execute(t_token *begin, int index, char **envp)
{
	t_node	*node;
	int		res;

	node = parser(begin, index);
	res = execute_loop(node->root, envp, 0);
	unlink(HEREDOC);
	//free_node(node->root);
	return (res);
}
