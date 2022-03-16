/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:06:21 by gkgpteam          #+#    #+#             */
/*   Updated: 2022/03/14 20:30:57 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_display(t_app *app)
{
	t_list		**plist;
	t_keyval	*keyval;

	plist = &app->env;
	while (*plist)
	{	
		keyval = (t_keyval *)(*plist)->data;
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(keyval->key, 1);
		ft_putstr_fd("=\"", 1);
		ft_putstr_fd(keyval->val, 1);
		ft_putstr_fd("\"\n", 1);
		plist = &((*plist)->next);
	}
	return (0);
}

int	ft_export(t_app *app, char **args)
{
	char		*str;
	char		*x;
	int			added;
	int			i;

	if (!args[0])
		return (ft_display(app));
	i = -1;
	while (args[++i])
	{
		str = ft_strdup(args[i]);
		x = ft_strchr(str, '=');
		if (x == 0 || *(x + 1) == '\0' || x == str)
		{
			ft_putstr_fd("bad key=value for ", 2);
			ft_putstr_fd(str, 2);
			ft_putstr_fd("\n", 2);
			free(str);
			return (1);
		}
		*x = '\0';
		added = ft_setenv(app, str, x + 1);
		free(str);
	}
	return (0);
}
