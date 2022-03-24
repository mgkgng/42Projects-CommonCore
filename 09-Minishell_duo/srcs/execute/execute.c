/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:54:12 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/16 20:46:01 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	do_cmd_execute(t_node *node, int *fd, char **envp)
{
	char		*cmd_path;

	cmd_path = path_define(node->left->args[0], envp);
	execve(cmd_path, node->left->args, envp);
	write(fd[1], "", 1);
	exit(127);
	return (1);
}

int	cmd_execute(t_app *app, t_node *node, int *fd)
{
	t_redir		redir;
	int			exit_code;
	int			copy[2];

	if (fd[2])
	{
		copy[0] = dup(STDIN_FILENO);
		copy[1] = dup(STDOUT_FILENO);
	}
	redir = redir_initialize(fd[0], fd[1]);
	if (node->right && (redir_define(&redir, node->right->redir_name,
				node->right->redir_type, fd[2])))
		return (1);
	dup2_2d(redir.input, redir.output);
	exit_code = builtin_execute(node->left, app, fd[2]);
	if (exit_code >= 0)
	{
		dup2_2d(copy[0], copy[1]);
		if (fd[2])
			return (exit_code);
		else
			exit(exit_code);
	}
	return (do_cmd_execute(node, fd, app->envp));
}

int	execute_loop(t_app *app, t_node *node, int fd_in)
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
			proc_child(app, node, fd_in, fd);
		else
			res = proc_parent(app, node, fd, pid);
	}
	return (res);
}

int	parse_execute(t_app *app, t_token *begin, int index)
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
	if (node->root->node_type == 2 && builtin_check(node->root->left) != -1)
		res = cmd_execute(app, node->root, (int [3]){0, 1, 1});
	else
		res = execute_loop(app, node->root, 0);
	free_node(node->root);
	free(node);
	unlink(HEREDOC);
	return (res);
}
