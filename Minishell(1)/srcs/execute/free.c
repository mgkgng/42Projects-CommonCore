/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:52:42 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/21 14:52:43 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	preorder_traversal(t_node *node)
{
	printf("====brrr===%d\n", node->node_type);
	if (node->left)
		preorder_traversal(node->left);
	if (node->right)
		preorder_traversal(node->right);
}

void	free_node(t_node *node)
{
}
