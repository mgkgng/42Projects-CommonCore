/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cavalier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:01:54 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/17 21:37:32 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	define_point_cavalier(t_fdf fdf, t_3d point, t_main main)
{
	float	x2;
	float	y2;
	t_point	result;

	x2 = point.x;
	y2 = point.y;
	result.x = roundf(fdf.start_x + (x2 - y2 * 0.5)
			* fdf.size + main.event.move_right_light * 5);
	result.y = roundf(fdf.start_y + y2 * 0.5 * fdf.size
			- point.z * fdf.size * 0.05 - main.event.move_up_down * 5);
	result.h = point.h;
	return (result);
}

int	define_size_cavalier(t_main main)
{
	int	i;

	i = 0;
	while (i * main.data.len_line < FDF_WIN_SIZE_X * 0.3)
		i++;
	return (i);
}

t_fdf	fdf_define(t_main *main)
{
	t_fdf	fdf;

	fdf.size = define_size_cavalier(*main) * pow(1.1, main->event.zoom_in_out);
	fdf.start_x = FDF_WIN_X + FDF_WIN_SIZE_X * 0.4;
	fdf.start_y = FDF_WIN_Y + FDF_WIN_SIZE_Y * 0.4;
	return (fdf);
}

void	vas_y(t_fdf fdf, t_main *main)
{
	int		index;
	t_point	point;
	t_point	to_point;

	index = -1;
	while (++index < main->data.size)
	{
		point = define_point_cavalier(fdf, main->data.mat_3d[index], *main);
		if (draw_condition(point.x, point.y))
			my_mlx_pixel_put(&main->img, point.x, point.y,
				put_color(main->data.max, main->data.min,
					main->data.mat_3d[index].h));
		if (index % main->data.len_line < main->data.len_line - 1)
		{
			to_point = define_point_cavalier(fdf, main->data.mat_3d[index + 1],
					*main);
			bresenham(main->img, main->data, point, to_point);
		}
		if (index / main->data.len_line < main->data.n_line - 1)
		{
			to_point = define_point_cavalier(fdf,
					main->data.mat_3d[index + main->data.len_line], *main);
			bresenham(main->img, main->data, point, to_point);
		}
	}
}

void	draw_cavalier(t_main main)
{
	t_fdf	fdf;

	fdf = fdf_define(&main);
	if (main.event.rotation_x || main.event.rotation_y
		|| main.event.rotation_z)
		rotation(&main.data, &main.event);
	vas_y(fdf, &main);
	mlx_put_image_to_window(main.vars.mlx, main.vars.win, main.img.img, 0, 0);
}
