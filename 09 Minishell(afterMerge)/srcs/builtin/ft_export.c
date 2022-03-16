/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:06:21 by gkgpteam          #+#    #+#             */
/*   Updated: 2022/03/16 20:54:26 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_putstr_escaped(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '\\' || s[i] == '\"')
			write(1, "\\", 1);
		write(1, &s[i], 1);
	}
}

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
		ft_putstr_escaped(keyval->val);
		ft_putstr_fd("\"\n", 1);
		plist = &((*plist)->next);
	}
	return (0);
}

static int	ft_export_error(char *str)
{
	ft_putstr_fd("minshell: export: `", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("': not a valid identifier", 2);
	ft_putstr_fd("\n", 2);
	free(str);
	return (1);
}

static int	ft_export_is_valid_identifier(char c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || c == '_')
		return (1);
	return (0);
}

int	ft_export(t_app *app, char **args)
{
	char		*str;
	char		*x;
	int			i;

	if (!args[0])
		return (ft_display(app));
	i = -1;
	while (args[++i])
	{
		str = ft_strdup(args[i]);
		x = ft_strchr(str, '=');
		if (x == str || (*str && !ft_export_is_valid_identifier(*str)))
			return (ft_export_error(str));
		else if (x == 0)
		{
			ft_setenv(app, str, "\0", 1);
			free(str);
			return (0);
		}
		*x = '\0';
		ft_setenv(app, str, x + 1, 0);
		free(str);
	}
	return (0);
}
