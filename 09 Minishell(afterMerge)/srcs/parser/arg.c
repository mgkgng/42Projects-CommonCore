/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:24:20 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/13 13:38:13 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*arg_begin(char *s)
{
	t_node	*nov;

	nov = ft_calloc(1, sizeof(t_node));
	nov->node_type = 0;
	nov->args = malloc(sizeof(char *) * 2);
	nov->args[0] = s;
	nov->args[1] = NULL;
	return (nov);
}

void	arg_join(t_node **node, char *join)
{
	int		i;
	int		count;
	char	**new;

	i = -1;
	count = 0;
	while ((*node)->current_cmd->left->args[++i])
		count++;
	new = malloc(sizeof(char *) * (count + 2));
	i = -1;
	while ((*node)->current_cmd->left->args[++i])
		new[i] = (*node)->current_cmd->left->args[i];
	new[i++] = join;
	new[i] = NULL;
	free((*node)->current_cmd->left->args);
	(*node)->current_cmd->left->args = new;
}

void	parse_cmd(t_node **node, char *new_arg)
{
	t_node	*new;

	if ((*node)->current_cmd)
	{
		if ((*node)->current_cmd->left)
			arg_join(node, new_arg);
		else
			(*node)->current_cmd->left = arg_begin(new_arg);
	}
	else
	{
		new = ft_calloc(1, sizeof(t_node));
		new->node_type = 2;
		new->left = arg_begin(new_arg);
		(*node)->current_cmd = new;
		if (!(*node)->root)
			(*node)->root = new;
	}
}
