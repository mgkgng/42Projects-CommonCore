/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:25:23 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/27 13:53:49 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	p_couple(t_token *tokens)
{
	int	count;

	count = 1;
	while (count)
	{
		tokens = tokens->next;
		if (tokens->token == P_OPEN)
			count++;
		if (tokens->token == P_CLOSE)
			count--;
	}
	return (tokens->index);
}

void	p_jump(t_token **tokens)
{
	int	p_end;

	p_end = p_couple(*tokens);
	while ((*tokens)->index != p_end)
		*tokens = (*tokens)->next;
	*tokens = (*tokens)->next;
}

int	subshell(t_token *tokens, char **envp)
{
	pid_t	pid;
	int		p_end;
	int		res;

	pid = fork();
	if (pid == 0)
	{
		p_end = p_couple(tokens);
		res = minishell(tokens->next, p_end, envp);
		exit(res);
	}
	else
		waitpid(pid, &res, 0);
	return (WEXITSTATUS(res));
}

int	break_or_continue(int res, int token)
{
	if ((res && token == AND) || (!res && token == OR))
		return (0);
	else
		return (1);
}

int	minishell(t_token *tokens, int index, char **envp)
{
	t_node	*node;
	t_token	*begin;
	int		res;

	while (tokens && (tokens->index <= index || !index))
	{
		if (tokens->token == P_OPEN)
		{
			res = subshell(tokens, envp);
			p_jump(&tokens);
			if (!tokens || !break_or_continue(res, tokens->token))
				break ;
		}
		if (tokens->begin)
			begin = tokens;
		if (tokens->token == OR || tokens->token == AND
			|| tokens->token == P_CLOSE || !tokens->next)
		{
			node = parser(begin, tokens->index);
			res = execute(node, envp);
			if (!tokens->next || !break_or_continue(res, tokens->token))
				break ;
		}
		tokens = tokens->next;
	}
	return (res);
}
