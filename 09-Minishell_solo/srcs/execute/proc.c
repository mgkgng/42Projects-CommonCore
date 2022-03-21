/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:17:12 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/20 15:17:20 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
