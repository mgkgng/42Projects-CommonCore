/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:02:10 by gkgpteam          #+#    #+#             */
/*   Updated: 2022/03/14 20:45:33 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_isnumeric(char *str)
{
	while (str && *str)
	{
		if (!('0' <= *str && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

int	ft_exit(int pid, char **args)
{
	if (!ft_isnumeric(*args))
	{
		ft_putstr("minshell: exit: ");
		ft_putstr(*args);
		ft_putstr(": numeric argument required\n");
	}
	else if (args[0] && args[1])
	{
		ft_putstr_fd("minshell: exit: too many arguments\n", 2);
		return (0);
	}
	if (pid != 0)
		ft_putstr("exit\n");
	exit(0);
	return (0);
}
