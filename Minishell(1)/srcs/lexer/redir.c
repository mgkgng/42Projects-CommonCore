/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:55:48 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/16 16:56:00 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	redir_input(t_token **tokens, char *s, int index)
{
	t_token	*new;
	int		i;

	i = index;
	new = ft_calloc(1, sizeof(t_token));
	if (s[i + 1] == '<')
	{
		new->token = DOUBLE_CHEVRON_I;
		new->next = ft_calloc(1, sizeof(t_token));
		new->next->token = LIMITER;
		new->next->content = put_arg(s, i + 2);
		i = arg_len(s, i + 2, 0);
	}
	else
	{
		new->token = CHEVRON_I;
		new->next = ft_calloc(1, sizeof(t_token));
		new->next->token = INPUT;
		new->next->content = put_arg(s, i + 1);
		i = arg_len(s, i + 1, 0);
	}
	token_addback(tokens, new);
	return (i);
}

int	redir_output(t_token **tokens, char *s, int index)
{
	int		i;
	t_token	*new;

	new = ft_calloc(1, sizeof(t_token));
	i = index;
	if (s[i + 1] == '>')
	{
		new->token = DOUBLE_CHEVRON_O;
		new->next = ft_calloc(1, sizeof(t_token));
		new->next->token = OUTPUT_A;
		new->next->content = put_arg(s, i + 2);
		i = arg_len(s, i + 2, 0);
	}
	else
	{
		new->token = CHEVRON_O;
		new->next = ft_calloc(1, sizeof(t_token));
		new->next->token = OUTPUT_T;
		new->next->content = put_arg(s, i + 1);
		i = arg_len(s, i + 1, 0);
	}
	token_addback(tokens, new);
	return (i);
}
