/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:48:27 by min-kang          #+#    #+#             */
/*   Updated: 2021/12/20 14:48:28 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	define_point(t_fdf fdf, t_3d point, t_main main)
{
	float	swap_x;
	float	swap_y;
	t_point	result;

	swap_x = point.x;
	swap_y = point.y;
	result.x = roundf(fdf.start_x + (swap_x - swap_y)
			* fdf.size * 2 + main.event.move_right_light * 5);
	result.y = roundf(fdf.start_y + (swap_x + swap_y) * fdf.size
			- point.z * fdf.size * 0.1 - main.event.move_up_down * 5);
	result.h = point.h;
	return (result);
}

int	start_x_define(t_map data, t_fdf fdf)
{
	int	i;
	int	j;

	i = FDF_WIN_X;
	j = FDF_WIN_X + FDF_WIN_SIZE_X;
	while (i - data.n_line * fdf.size * 2 < FDF_WIN_X + FDF_WIN_SIZE_X * 0.1)
		i++;
	while (j + data.len_line * fdf.size * 2 > FDF_WIN_X + FDF_WIN_SIZE_X * 0.9)
		j--;
	return ((i + j) / 2);
}
