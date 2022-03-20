/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:25:07 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/20 15:49:08 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	free_env(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
		free(envp[i]);
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
		if (tokens)
		{
			g_res = minishell(tokens, 0, env);
			free(tokens);
		}
		else
			g_res = 258;
		free(r);
	}
	free(env);
	return (g_res);
}
