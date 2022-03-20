/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:03:47 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/20 15:06:15 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(char *s, int type)
{
	ft_putstr_fd("minshell: ", 2);
	ft_putstr_fd(s, 2);
	if (type == 1)
		ft_putstr_fd(": No such file or directory.\n", 2);
	if (type == 2)
		ft_putstr_fd(": command not found\n", 2);
	if (type == 3)
		ft_putstr_fd(": is a directory\n", 2);
}
