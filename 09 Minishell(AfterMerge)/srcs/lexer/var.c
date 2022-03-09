/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:56:06 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/21 16:28:32 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var_arg(char *s)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	res = malloc(ft_strlen(s) - i);
	j = 0;
	while (s[++i])
		res[j++] = s[i];
	res[j] = '\0';
	return (res);
}

char	*find_var(char *s, char **envp)
{
	int		i;
	char	*compare;

	compare = ft_strjoin(s, "=", 0);
	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(compare, envp[i], ft_strlen(compare)))
		{
			free(compare);
			return (get_var_arg(envp[i]));
		}
	}
	return (ft_strdup(""));
}

int	len_varname(char *s, int i)
{
	while (s[i] && s[i] != ' ' && s[i] != '\"' && s[i] != '\'' && s[i] != '$')
		i++;
	return (i);
}

char	*get_var(char *s, int i, char **envp)
{
	int		index;
	int		j;
	char	*var_name;

	index = i;
	while (s[index] && s[index] != '\"' && s[index] != '\'' && s[index] != ' ')
		index++;
	var_name = ft_calloc(index - i + 1, sizeof(char));
	j = 0;
	while (i < index)
		var_name[j++] = s[i++];
	var_name[j] = '\0';
	return (find_var(var_name, envp));
}

int	put_var(char **res, char *s, int i, char **envp)
{
	char	*var;

	if (!s[i + 1] || s[i + 1] == ' ')
		*res = ft_strfcat(*res, '$');
	else if (s[i + 1] == '?')
	{
		var = ft_itoa(g_res);
		i += 2;
		*res = ft_strjoin(*res, var, 0);
		free(var);
	}
	else
	{
		var = get_var(s, i + 1, envp);
		i = len_varname(s, i + 1);
		*res = ft_strjoin(*res, var, 0);
		free(var);
	}
	return (i - 1);
}
