/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:18:47 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/16 21:07:35 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	p_check(t_token *tokens)
{
	int	p_count;

	p_count = 0;
	while (tokens)
	{
		if (tokens->token == P_OPEN)
			p_count++;
		if (tokens->token == P_CLOSE)
			p_count--;
		tokens = tokens->next;
	}
	return (p_count);
}

static int	check_error(t_token *tokens)
{
	if (p_check(tokens))
		return (1);
	while (tokens)
	{
		if ((tokens->token >= PIPE && tokens->token <= AND) && tokens->next
			&& (tokens->next->token >= PIPE && tokens->next->token <= AND))
			return (2);
		if ((tokens->token == P_CLOSE) && tokens->next
			&& tokens->next->token == ARG)
			return (3);
		if ((tokens->token >= INPUT && tokens->token <= OUTPUT_A)
			&& !tokens->content)
			return (4);
		if (tokens->token == P_OPEN && tokens->next
			&& ((tokens->next->token >= PIPE && tokens->next->token <= AND)
				|| tokens->next->token == P_CLOSE))
			return (5);
		if (!tokens->next && (tokens->token >= PIPE && tokens->token <= P_OPEN))
			return (6);
		tokens = tokens->next;
	}
	return (0);
}

int	lexer_error(t_token *tokens)
{
	if (check_error(tokens))
	{
		ft_putstr_fd("Syntax error.\n", 2);
		return (0);
	}
	return (1);
}
