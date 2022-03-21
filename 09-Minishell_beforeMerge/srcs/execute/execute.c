/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:54:12 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/20 15:17:07 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	if (!node->root)
	{
		free(node);
		return (0);
	}
	else if (!node->root->left)
	{
		free_node(node->root);
		free(node);
		return (0);
	}
	res = execute_loop(node->root, envp, 0);
	free_node(node->root);
	free(node);
	unlink(HEREDOC);
	return (res);
}
