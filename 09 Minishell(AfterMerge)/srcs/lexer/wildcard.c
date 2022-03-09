/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:02:06 by gkgpteam          #+#    #+#             */
/*   Updated: 2022/02/23 17:22:01 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_wordlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != ' ')
		i++;
	return (i);
}

int	rewrite_wildcard(t_token **tokens, char *s, int index)
{
	t_token		*new;
	char		*pwd;
	char		**args;
	char		length;
	int			i;

	i = -1;
	pwd = ft_getcwd();
	args = wildcard(pwd);
	length = ft_wordlen(&s[index]);
	while (args[++i])
	{
		if (length > 1 && ft_strncmp(&s[index + 1], args[i], length) != 0)
		{
			free(args[i]);
			continue ;
		}
		new = ft_calloc(1, sizeof(t_token));
		new->token = ARG;
		new->content = args[i];
		token_addback(tokens, new);
	}
	free(args);
	free(pwd);
	return (index + length);
}
