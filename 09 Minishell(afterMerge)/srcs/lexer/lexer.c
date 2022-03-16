/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:28:00 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/16 13:50:04 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	do_lexer(int i, char *s, char **envp, t_token	**tokens)
{
	if (is_arg(s[i]))
		i = get_arg(tokens, s, i, envp);
	else if (s[i] == '<')
		i = redir_input(tokens, s, i);
	else if (s[i] == '>')
		i = redir_output(tokens, s, i);
	else if (s[i] == '|' && s[i + 1] != '|')
		i = give_token(tokens, PIPE, i);
	else if (s[i] == '|' && s[i + 1] == '|')
		i = give_token(tokens, OR, i);
	else if (s[i] == '&' && s[i + 1] == '&')
		i = give_token(tokens, AND, i);
	else if (s[i] == '(')
		i = give_token(tokens, P_OPEN, i);
	else if (s[i] == ')')
		i = give_token(tokens, P_CLOSE, i);
	else
		i++;
	return (i);
}

t_token	*lexer(char *s, char **envp)
{
	int				i;
	t_token			*tokens;

	tokens = NULL;
	i = 0;
	while (i < ft_strlen(s))
	{
		while (s[i] == ' ')
			i++;
		i = do_lexer(i, s, envp, &tokens);
	}
	if (!lexer_error(tokens))
		return (free_tokens(tokens));
	put_token_index(&tokens);
	put_begin(&tokens);
	return (tokens);
}
