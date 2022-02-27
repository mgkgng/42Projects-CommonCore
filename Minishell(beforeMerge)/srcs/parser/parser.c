/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:24:50 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/27 14:44:26 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node	*parser(t_token *tokens, int index)
{
	t_node	*node;
	t_node	*tmp;
	t_token	*begin;

	begin = tokens;
	node = ft_calloc(1, sizeof(t_node));
	tmp = NULL;
	while (tokens && (tokens->index <= index || index == -1))
	{
		if (tokens->token == ARG)
			parse_cmd(&node, tokens->content);
		else if (tokens->token >= CHEVRON_I
			&& tokens->token <= DOUBLE_CHEVRON_O)
			parse_redir(&node, &tokens);
		else if (tokens->token == PIPE)
			parse_pipe(&node);
		tokens = tokens->next;
	}
	last_cmd(&node);
	return (node);
}
