/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:56:28 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/27 14:23:16 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	token_addback(t_token **tokens, t_token *new)
{
	t_token	*begin;

	if (!*tokens)
	{
		*tokens = new;
		return ;
	}
	begin = *tokens;
	while ((*tokens)->next)
		*tokens = (*tokens)->next;
	(*tokens)->next = new;
	*tokens = begin;
}

int	give_token(t_token **tokens, char *s, int i)
{
	t_token	*new;

	new = ft_calloc(1, sizeof(t_token));
	if (s[i] == '|' && s[i + 1] != '|')
		new->token = PIPE;
	else if (s[i] == '|' && s[i + 1] == '|')
		new->token = OR;
	else if (s[i] == '&' && s[i + 1] == '&')
		new->token = AND;
	else if (s[i] == '(')
		new->token = P_OPEN;
	else if (s[i] == ')')
		new->token = P_CLOSE;
	new->next = NULL;
	token_addback(tokens, new);
	if (new->token == OR || new->token == AND)
		return (i + 2);
	else
		return (i + 1);
}

int	lexer_error(t_token *tokens)
{
	while (tokens)
	{
		if ((tokens->token >= CHEVRON_I && tokens->token <= P_OPEN)
			&& !tokens->next)
		{
			ft_putstr_fd("Syntax error.\n", 2);
			return (0);
		}
		if ((tokens->token >= PIPE && tokens->token <= AND)
			&& (tokens->next->token >= PIPE && tokens->next->token <= AND))
		{
			ft_putstr_fd("Syntax error.\n", 2);
			return (0);
		}
		tokens = tokens->next;
	}
	return (1);
}

void	put_token_index(t_token **tokens)
{
	t_token	*begin;
	int		index;

	begin = *tokens;
	index = 0;
	while (*tokens)
	{
		(*tokens)->index = index++;
		*tokens = (*tokens)->next;
	}
	*tokens = begin;
}

void	put_begin(t_token **tokens)
{
	int		flag;
	t_token	*begin;

	begin = *tokens;
	flag = 1;
	while (*tokens)
	{
		if ((*tokens)->token == P_OPEN || (*tokens)->token == AND
			|| (*tokens)->token == OR)
			flag = 1;
		else if (flag)
		{
			(*tokens)->begin = 1;
			flag = 0;
		}
		*tokens = (*tokens)->next;
	}
	*tokens = begin;
}
