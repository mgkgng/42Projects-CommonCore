/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:18:30 by min-kang          #+#    #+#             */
/*   Updated: 2021/12/19 20:18:31 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	min_find(t_map data)
{
	int	i;
	int	min;

	min = data.mat_3d[0].z;
	i = 0;
	while (++i < data.len_line * data.n_line)
		if (min > data.mat_3d[i].z)
			min = data.mat_3d[i].z;
	return (min);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
}
