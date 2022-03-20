/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:28:00 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/20 15:23:25 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	str_err(char *s, int i)
{
	while (s[i] == ' ')
		i++;
	if (s[i] == '|' || s[i] == '&' || s[i] == ')')
	{
		ft_putstr_fd("Syntax error.\n", 2);
		return (1);
	}
	return (0);
}

static int	check_err(char *s, int i)
{
	if (s[i] == '(' && s[i + 1] && (s[i + 1] == '|' || s[i + 1] == '&'))
	{
		ft_putstr_fd("Syntax error.\n", 2);
		return (1);
	}
	return (0);
}

static int	do_lexer(int i, char *s, char **envp, t_token	**tokens)
{
	if (check_err(s, i))
		return (-1);
	else if (is_arg(s[i]))
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
	if (str_err(s, i))
		return (NULL);
	while (i < ft_strlen(s))
	{
		while (s[i] == ' ')
			i++;
		i = do_lexer(i, s, envp, &tokens);
		if (i == -1)
			return (free_tokens(tokens));
	}
	if (!lexer_error(tokens))
		return (free_tokens(tokens));
	put_token_index(&tokens);
	put_begin(&tokens);
	return (tokens);
}
