/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:24:32 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/27 14:44:21 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node	*last_node(t_node *node)
{
	while (node->right)
		node = node->right;
	return (node);
}

void	last_cmd(t_node **node)
{
	t_node	*current;

	if ((*node)->current_cmd && ((*node)->current_pipe))
	{
		current = last_node((*node)->root);
		current->right = (*node)->current_cmd;
		(*node)->current_cmd = NULL;
	}
}
