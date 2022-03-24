/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:24:47 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/16 15:35:23 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_node	*redir_begin(int redir_type, char *redir_name)
{
	int		*new_type;
	char	**new_name;
	t_node	*new;

	new = ft_calloc(1, sizeof(t_node));
	new_type = malloc(sizeof(int) * 2);
	new_type[0] = redir_type;
	new_type[1] = -1;
	new_name = malloc(sizeof(char *) * 2);
	new_name[0] = ft_strdup(redir_name);
	new_name[1] = NULL;
	new->node_type = 1;
	new->redir_type = new_type;
	new->redir_name = new_name;
	return (new);
}

void	redir_join(t_node **node, int redir_type, char *redir_name, int i)
{
	int		*new_type;
	char	**new_name;

	while ((*node)->current_cmd->right->redir_type[i] != -1)
		i++;
	new_type = malloc(sizeof(int) * (i + 2));
	i = 0;
	while ((*node)->current_cmd->right->redir_name[i])
		i++;
	new_name = malloc(sizeof(char *) * (i + 2));
	i = -1;
	while ((*node)->current_cmd->right->redir_type[++i] != -1)
		new_type[i] = (*node)->current_cmd->right->redir_type[i];
	new_type[i++] = redir_type;
	new_type[i] = -1;
	i = -1;
	while ((*node)->current_cmd->right->redir_name[++i])
		new_name[i] = (*node)->current_cmd->right->redir_name[i];
	new_name[i++] = ft_strdup(redir_name);
	new_name[i] = NULL;
	free((*node)->current_cmd->right->redir_type);
	free((*node)->current_cmd->right->redir_name);
	(*node)->current_cmd->right->redir_type = new_type;
	(*node)->current_cmd->right->redir_name = new_name;
}

void	parse_redir(t_node **node, t_token **tokens)
{
	t_node	*nov;

	if ((*node)->current_cmd)
	{
		if ((*node)->current_cmd->right)
			redir_join(node, (*tokens)->token, (*tokens)->next->content, 0);
		else
			(*node)->current_cmd->right = redir_begin((*tokens)->token,
					(*tokens)->next->content);
	}
	else
	{
		nov = ft_calloc(1, sizeof(t_node));
		nov->node_type = 2;
		nov->right = redir_begin((*tokens)->token, (*tokens)->next->content);
		(*node)->current_cmd = nov;
		if (!(*node)->root)
			(*node)->root = nov;
	}
	*tokens = (*tokens)->next;
}
