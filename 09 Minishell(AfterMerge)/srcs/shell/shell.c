/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:25:23 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/09 16:05:46 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	p_couple(t_token *tokens)
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

static void	p_jump(t_token **tokens)
{
	int	p_end;

	p_end = p_couple(*tokens);
	while ((*tokens)->index != p_end)
		*tokens = (*tokens)->next;
	*tokens = (*tokens)->next;
}

static int	subshell(t_app *app, t_token **tokens, char **envp)
{
	pid_t	pid;
	int		p_end;
	int		res;

	pid = fork();
	if (pid == 0)
	{
		p_end = p_couple(*tokens);
		res = shell(app, (*tokens)->next, p_end, envp);
		exit(res);
	}
	else
		waitpid(pid, &res, 0);
	p_jump(tokens);
	return (WEXITSTATUS(res));
}

int	break_or_continue(int res, int token)
{
	if ((res && token == AND) || (!res && token == OR))
		return (0);
	else
		return (1);
}

int	shell(t_app *app, t_token *tokens, int index, char **envp)
{
	t_token	*begin;
	int		res;

	while (tokens && (tokens->index <= index || !index))
	{
		if (tokens->token == P_OPEN)
		{
			res = subshell(app, &tokens, envp);
			if (!tokens || !break_or_continue(res, tokens->token))
				break ;
			tokens = tokens->next;
		}
		if (tokens->begin)
			begin = tokens;
		if (tokens->token == AND || tokens->token == OR
			|| tokens->token == P_CLOSE || !tokens->next)
		{
			res = parse_execute(app, begin, tokens->index, envp);
			if (!tokens->next || !break_or_continue(res, tokens->token))
				break ;
		}
		tokens = tokens->next;
	}
	return (res);
}
