/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:24:43 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/21 16:26:21 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_pipe(t_node **node)
{
	t_node	*new;
	t_node	*tmp;

	new = ft_calloc(1, sizeof(t_node));
	new->node_type = 3;
	new->left = (*node)->current_cmd;
	(*node)->current_cmd = NULL;
	if ((*node)->current_pipe)
	{
		tmp = last_node((*node)->current_pipe);
		tmp->right = new;
	}
	else
	{
		(*node)->current_pipe = new;
		if ((*node)->root->node_type < 3)
			(*node)->root = (*node)->current_pipe;
	}
}
