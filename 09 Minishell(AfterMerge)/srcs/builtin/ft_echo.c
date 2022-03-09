/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:37:45 by gkgpteam          #+#    #+#             */
/*   Updated: 2022/02/23 15:35:59 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char **args)
{
	int			flag_n;
	int			i;

	if (!args || !*args)
		return (0);
	i = -1;
	flag_n = (ft_strcmp("-n", args[i + 1]) == 0 && ++i >= 0);
	while (args[++i])
	{
		if (i - flag_n > 0)
			ft_putstr_fd(" ", 1);
		ft_putstr_fd(args[i], 1);
	}
	if (!flag_n)
		ft_putstr_fd("\n", 1);
	return (0);
}
