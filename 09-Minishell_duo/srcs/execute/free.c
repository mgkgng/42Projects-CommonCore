/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:52:42 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/15 19:35:09 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args && args[i])
		free(args[i++]);
	free(args);
}

void	free_redir(t_node *node)
{
	int	i;

	free(node->redir_type);
	i = 0;
	while (node->redir_name[i])
		free(node->redir_name[i++]);
	free(node->redir_name);
}

void	free_node(t_node *node)
{
	if (node->left)
		free_node(node->left);
	if (node->right)
		free_node(node->right);
	if (node->node_type < 2)
	{
		if (!node->node_type)
			free_args(node->args);
		else
			free_redir(node);
	}
	free(node);
}
