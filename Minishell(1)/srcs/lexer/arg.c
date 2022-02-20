/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:02:06 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/16 17:02:17 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_arg(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else if ((c >= 22 && c <= 64) && c != '&' && c != '(' && c != ')'
		&& c != '*' && c != '<' && c != '>')
		return (1);
	else if ((c >= 91 && c <= 96) || ((c >= 123 && c <= 126) && c != '|'))
		return (1);
	return (0);
}

int	arg_len(char *s, int index, int flag)
{
	int		i;
	int		count;

	i = index;
	count = 0;
	while (s[i] == ' ')
		i++;
	while (s[i] && s[i] != ' ' && is_arg(s[i]))
	{
		if (s[i] == '\'')
		{
			while (s[++i] != '\'')
				count++;
			if (!s[++i] || s[i] == ' ')
				break;
		}
		if (s[i] == '\"')
		{
			while (s[++i] != '\"')
				count++;
			if (!s[++i] || s[i] == ' ')
				break;
		}
		else
		{
			i++;
			count++;
		}
	}
	if (flag)
		return (count);
	return (i);
}

char	*put_arg(char *s, int index)
{
	int	i;
	int	j;
	int len;
	char	*result;

	len = arg_len(s, index, 1);
	result = ft_calloc(1, sizeof(char) * (len + 1));
	i = index;
	while (s[i] == ' ')
		i++;
	j = 0;
	while (j < len)
	{
		if (s[i] == '\'')
			while (s[++i] != '\'')
				result[j++] = s[i];
		else if (s[i] == '\"')
		{
			while (s[++i] != '\"')
				result[j++] = s[i];
		}
		else
			result[j++] = s[i++];
	}
	result[j] = '\0';
	return (result);
}

char	*put_arg2(char *s, int i, char **envp)
{
	char	*res;

	res = NULL;
	while (s[i] && s[i] != ' ' && is_arg(s[i]))
	{
		if (s[i] == '\'')
			while (s[++i] != '\'')
				res = ft_strcat(res, s[i]);
		else if (s[i] == '\"')
		{
			while (s[++i] != '\"')
			{
				if (s[i] == '$')
					i = put_var(&res, s, i, envp);
				else
					res = ft_strcat(res, s[i]);
			}
		}
		else if (s[i] == '$')
			i = put_var(&res, s, i, envp);
		else
			res = ft_strcat(res, s[i]);
		i++;
	}
	return (res);
}

int	get_arg(t_token **tokens, char *s, int index, char **envp)
{
	t_token *new;

	new = ft_calloc(1, sizeof(t_token));
	new->token = ARG;
	new->content = put_arg2(s, index, envp);
	token_addback(tokens, new);
	return (arg_len(s, index, 0));
}
