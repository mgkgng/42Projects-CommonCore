/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:02:53 by min-kang          #+#    #+#             */
/*   Updated: 2021/12/19 20:15:46 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_map *data, int direction)
{
	int		i;
	float	swap_y;
	float	swap_z;
	float	av;
	float	angle;

	angle = 0.05 * direction;
	av = ((float) data->max + (float) data->min) / 2;
	i = -1;
	while (++i < data->size)
	{
		swap_y = data->mat_3d[i].y;
		swap_z = data->mat_3d[i].z;
		data->mat_3d[i].y = swap_y * cos(angle) - swap_z * sin(angle)
			+ ((float) data->n_line / 2) * (1 - cos(angle)) + av * sin(angle);
		data->mat_3d[i].z = swap_y * sin(angle) + swap_z * cos(angle)
			+ av * (1 - cos(angle)) - ((float) data->n_line / 2) * sin(angle);
	}
}

void	rotate_y(t_map *data, int direction)
{
	int		i;
	float	swap_x;
	float	swap_z;
	float	av;
	float	angle;

	i = -1;
	angle = 0.05 * direction;
	av = ((float) data->max + (float) data->min) / 2;
	while (++i < data->size)
	{
		swap_x = data->mat_3d[i].x;
		swap_z = data->mat_3d[i].z;
		data->mat_3d[i].z = (swap_z - av) * cos(angle) - (swap_x
				- (float) data->len_line / 2) * sin(angle) + av;
		data->mat_3d[i].x = (swap_z - av) * sin(angle) + (swap_x
				- (float) data->len_line / 2) * cos(angle)
			+ (float) data->len_line / 2;
	}
}

void	rotate_z(t_map *data, int direction)
{
	int		i;
	float	swap_x;
	float	swap_y;

	i = -1;
	while (++i < data->size)
	{
		swap_x = data->mat_3d[i].x;
		swap_y = data->mat_3d[i].y;
		data->mat_3d[i].x = (swap_x - data->len_line / 2)
			* cos(0.05 * direction) - (swap_y - data->n_line / 2)
			* sin(0.05 * direction) + data->len_line / 2;
		data->mat_3d[i].y = (swap_x - data->len_line / 2)
			* sin(0.05 * direction) + (swap_y - data->n_line / 2)
			* cos(0.05 * direction) + data->n_line / 2;
	}
}
