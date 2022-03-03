/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:25:07 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/27 13:48:32 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_res;

char	**get_env(char **envp)
{
	int		i;
	char	**new;

	i = 0;
	while (envp[i])
		i++;
	new = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (envp[++i])
		new[i] = ft_strdup(envp[i]);
	new[i] = NULL;
	return (new);
}

int	main(int argc, char const *argv[], char **envp)
{
	char	*r;
	t_token	*tokens;
	char	**env;

	(void) argv;
	g_res = 0;
	if (argc != 1)
		return (0);
	env = get_env(envp);
	while (1)
	{
		r = readline("input: ");
		if (!r)
			break ;
		tokens = lexer(r, env);
		g_res = minishell(tokens, 0, env);
		free_tokens(tokens);
		free(r);
	}
	return (g_res);
}
