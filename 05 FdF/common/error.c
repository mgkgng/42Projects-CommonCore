/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:52:55 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/06 11:54:31 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	error(int code)
{
	if (code == 1)
		ft_putstr_fd("Error 1: Wrong argument number", 2);
	else if (code == 2)
		ft_putstr_fd("Error 2: Unable to read the file", 2);
	return (code);
}