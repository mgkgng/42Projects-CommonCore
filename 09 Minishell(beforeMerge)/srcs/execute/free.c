/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:52:42 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/15 18:43:13 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_node(t_node *node)
{
	int	i;

	if (node->left)
		free_node(node->left);
	if (node->right)
		free_node(node->right);
	if (node->node_type < 2)
	{
		if (!node->node_type)
			free(node->args);
		else
		{
			free(node->redir_type);
			i = 0;
			while (node->redir_name[i])
				free(node->redir_name[i++]);
			free(node->redir_name);
			i = 0;
			//while (node->heredoc[i])
			//	free(node->heredoc[i++]);
			free(node->heredoc);
		}
	}
	free(node);
}
