/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:28:00 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/09 15:55:52 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*lexer(char *s, char **envp)
{
	int		i;
	t_token	*tokens;

	tokens = NULL;
	i = 0;
	while (i < ft_strlen(s))
	{
		while (s[i] == ' ')
			i++;
		if (is_arg(s[i]))
			i = get_arg(&tokens, s, i, envp);
		else if (s[i] == '<')
			i = redir_input(&tokens, s, i);
		else if (s[i] == '>')
			i = redir_output(&tokens, s, i);
		else if (s[i] == '|' || (s[i] == '&' && s[i + 1] == '&')
			|| s[i] == '(' || s[i] == ')')
			i = give_token(&tokens, s, i);
	}
	if (!lexer_error(tokens))
		return (free_tokens(tokens));
	put_token_index(&tokens);
	put_begin(&tokens);
	return (tokens);
}
