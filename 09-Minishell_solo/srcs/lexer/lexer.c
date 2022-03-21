/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:28:00 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/20 15:37:23 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	do_lexer(t_token **tokens, char *s, int i, char **envp)
{
	if (check_err(s, i))
		return (-1);
	if (is_arg(s[i]))
		i = get_arg(tokens, s, i, envp);
	else if (s[i] == '<')
		i = redir_input(tokens, s, i);
	else if (s[i] == '>')
		i = redir_output(tokens, s, i);
	else if (s[i] == '|' || (s[i] == '&' && s[i + 1] == '&')
		|| s[i] == '(' || s[i] == ')')
		i = give_token(tokens, s, i);
	else
		i++;
	return (i);
}

t_token	*lexer(char *s, char **envp)
{
	int		i;
	t_token	*tokens;

	tokens = NULL;
	i = 0;
	if (str_err(s, i))
		return (NULL);
	while (i < ft_strlen(s))
	{
		while (s[i] == ' ')
			i++;
		i = do_lexer(&tokens, s, i, envp);
		if (i == -1)
			return (free_tokens(tokens));
	}
	if (!lexer_error(tokens))
		return (free_tokens(tokens));
	put_token_index(&tokens);
	put_begin(&tokens);
	return (tokens);
}
