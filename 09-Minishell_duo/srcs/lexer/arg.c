/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:02:06 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/16 20:25:10 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	in_quote(char *s, int index, char **envp, char **res)
{
	int		quote;

	quote = s[index];
	while (s[index] && s[++index] != quote)
	{
		if (s[index] == '$' && quote == '\"')
			index = put_var(res, s, index, envp);
		else
			*res = ft_strfcat(*res, s[index]);
	}
	return (index);
}

static char	*put_arg_n_var(char *s, int index, char **envp, int *wflag)
{
	char	*res;

	res = NULL;
	while (s && s[index] && s[index] != ' ' && is_arg(s[index]))
	{
		if (s[index] == '\'' || s[index] == '\"')
			index = in_quote(s, index, envp, &res);
		else if (s[index] == '$')
			index = put_var(&res, s, index, envp);
		else if (s[index] == '*' && (*wflag)++ >= 0)
			res = ft_strfcat(res, -42);
		else
			res = ft_strfcat(res, s[index]);
		index++;
	}
	return (res);
}

static t_token	*create_arg_token(char *str)
{
	t_token		*new;

	new = ft_calloc(1, sizeof(t_token));
	new->token = ARG;
	new->content = str;
	return (new);
}

int	get_arg(t_token **tokens, char *s, int index, char **envp)
{
	int				wflag;
	char			*str;
	int				i;

	wflag = 0;
	str = put_arg_n_var(s, index, envp, &wflag);
	if (wflag > 0 && rewrite_wildcard(tokens, str))
	{
		free(str);
		return (arg_len(s, index, 0));
	}
	else
	{
		i = -1;
		while (str && str[++i])
			if (str[i] == -42)
				str[i] = '*';
	}
	token_addback(tokens, create_arg_token(str));
	return (arg_len(s, index, 0));
}
