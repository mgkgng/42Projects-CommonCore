/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:36:08 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/16 13:02:51 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int  p_check(t_token *tokens)
{
    int p_count;

    p_count = 0;
    while (tokens)
    {
        if (tokens->token == P_OPEN)
            p_count++;
        if (tokens->token == P_CLOSE)
            p_count--;
        tokens = tokens->next;
    }
    if (!p_count)
        return (0);
    return (1);
}

static int check_error(t_token *tokens)
{
	while (tokens)
	{
		if (p_check(tokens))
			return (1);
		if ((tokens->token >= PIPE && tokens->token <= AND)
			&& (tokens->next->token >= PIPE && tokens->next->token <= AND))
			return (2);
		if ((tokens->token == P_CLOSE) && tokens->next->token == ARG)
			return (3);
        if ((tokens->token >= INPUT && tokens->token <= OUTPUT_A) && !tokens->content)
            return (4);
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