/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:24:44 by gkgpteam          #+#    #+#             */
/*   Updated: 2022/02/22 15:34:35 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env(t_app *app, char *const envp[])
{
	int			i;
	char		*x;
	t_keyval	*keyval;

	i = -1;
	while (envp[++i])
	{
		x = ft_strchr(envp[i], '=');
		if (x == 0)
		{
			ft_putstr("WARNING: Malformed path, value missing for ");
			ft_putstr(envp[i]);
			ft_putstr("\n");
			continue ;
		}
		*x = '\0';
		keyval = malloc(sizeof(t_keyval));
		*keyval = (t_keyval){ft_strdup(envp[i]), ft_strdup(x + 1)};
		*x = '=';
		list_push(&app->env, keyval);
	}
}

char	*ft_getenv(t_app *app, char *key)
{
	t_list		**plist;

	plist = &app->env;
	while (*plist)
	{
		if (ft_strcmp((*(t_keyval *)(*plist)->data).key, key) == 0)
			return ((*(t_keyval *)(*plist)->data).val);
		plist = &((*plist)->next);
	}
	return (NULL);
}

int	ft_setenv(t_app *app, char *key, char *val)
{
	t_list		**plist;
	t_keyval	*keyval;

	plist = &app->env;
	while (*plist)
	{
		keyval = (t_keyval *)(*plist)->data;
		if (ft_strcmp(keyval->key, key) == 0)
		{
			free(keyval->val);
			keyval->val = ft_strdup(val);
			return (0);
		}
		plist = &((*plist)->next);
	}
	keyval = malloc(sizeof(t_keyval));
	*keyval = (t_keyval){ft_strdup(key), ft_strdup(val)};
	list_push(&app->env, keyval);
	return (1);
}

int	ft_unsetenv(t_app *app, char *key)
{
	t_list		**plist;

	plist = &app->env;
	while (*plist)
	{
		if (ft_strcmp((*(t_keyval *)(*plist)->data).key, key) == 0)
		{
			list_free_keyval(list_shift(plist));
			return (1);
		}
		plist = &((*plist)->next);
	}
	return (0);
}

char	**list_env_to_2d(t_app *app)
{
	char		**envp;
	int			*length;
	int			i;
	t_list		**plist;
	t_keyval	*keyval;

	plist = &app->env;
	envp = malloc(sizeof(char *) * (list_length(*plist) + 1));
	i = 0;
	while (*plist)
	{	
		keyval = (t_keyval *)(*plist)->data;
		length = (int [2]){ft_strlen(keyval->key), ft_strlen(keyval->val)};
		envp[i] = malloc(sizeof(char) * (length[0] + 1 + length[1] + 1));
		envp[i][0] = '\0';
		ft_strcat(envp[i], keyval->key);
		envp[i][length[0]] = '=';
		envp[i][length[0] + 1] = '\0';
		ft_strcat(&envp[i][length[0] + 1], keyval->val);
		envp[i][length[0] + 1 + length[1]] = '\0';
		plist = &((*plist)->next);
		i++;
	}
	envp[i] = 0;
	return (envp);
}
