/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 10:52:52 by gkgpteam          #+#    #+#             */
/*   Updated: 2022/02/23 08:41:23 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(t_app *app, char **args)
{
	int			i;

	i = -1;
	while (args[++i])
		ft_unsetenv(app, args[i]);
	return (0);
}
