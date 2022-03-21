/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:20:11 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/16 17:52:25 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	proc_child(t_app *app, t_node *node, int fd_in, int *fd)
{
	close(fd[0]);
	if (node->right && node->right->node_type > 1)
		cmd_execute(app, node->left, (int [3]){fd_in, fd[1], 0});
	else
		cmd_execute(app, node, (int [3]){fd_in, STDOUT_FILENO, 0});
}

int	proc_parent(t_app *app, t_node *node, int *fd, pid_t pid)
{
	int	res;
	int	res_child;

	close(fd[1]);
	res = execute_loop(app, node->right, fd[0]);
	close(fd[0]);
	waitpid(pid, &res_child, 0);
	res_child = WEXITSTATUS(res_child);
	if (node->right && node->right->node_type > 1)
		return (res);
	return (res_child);
}
