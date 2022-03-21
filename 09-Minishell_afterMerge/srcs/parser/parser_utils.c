/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:24:32 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/21 16:26:19 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
