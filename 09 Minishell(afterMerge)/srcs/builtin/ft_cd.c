/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:14:24 by gkgpteam          #+#    #+#             */
/*   Updated: 2022/03/20 14:46:33 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <errno.h>

int	ft_cd(char *path)
{
	if (path == 0)
		return (1);
	if (chdir(path) != 0)
	{
		ft_putstr_fd("minshell: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd("No such file or directory", 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	return (0);
}
