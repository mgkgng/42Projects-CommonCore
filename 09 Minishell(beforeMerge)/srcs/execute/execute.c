/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:54:12 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/09 14:57:39 by min-kang         ###   ########.fr       */
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
	if (!cmd_path)
		exit(127);
	execve(cmd_path, node->left->args, envp);
	write(fd_out, "", 1);
	exit (127);
}

int	execute_loop(t_node *node, char **envp, int fd_in)
{
	int		fd[2];
	pid_t	pid;

	if (node && node->node_type > 1)
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			close(fd[0]);
			if (node->right && node->right->node_type > 1)
				cmd_execute(node->left, fd_in, fd[1], envp);
			else
				cmd_execute(node, fd_in, 1, envp);
		}
		else
		{
			close(fd[1]);
			execute_loop(node->right, envp, fd[0]);
			close(fd[0]);
			waitpid(pid, &g_res, 0);
		}
	}
	return (WEXITSTATUS(g_res));
}

int	parse_execute(t_token *begin, int index, char **envp)
{
	t_node	*node;
	int		res;

	node = parser(begin, index);
	res = execute_loop(node->root, envp, 0);
	unlink(HEREDOC);
	free_node(node);
	return (res);
}
