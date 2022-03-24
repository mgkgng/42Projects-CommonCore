/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 10:52:52 by gkgpteam          #+#    #+#             */
/*   Updated: 2022/03/16 19:02:15 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_unset_error(char *str)
{
	ft_putstr_fd("minshell: unset: `", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("': not a valid identifier", 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

static int	ft_unset_is_valid_identifier(char c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || c == '_')
		return (1);
	return (0);
}

int	ft_unset(t_app *app, char **args)
{
	int			i;
	char		*str;

	i = -1;
	while (args[++i])
	{
		str = args[i];
		if (*str && !ft_unset_is_valid_identifier(*str))
			ft_unset_error(str);
		else
			ft_unsetenv(app, str);
	}
	return (0);
}
