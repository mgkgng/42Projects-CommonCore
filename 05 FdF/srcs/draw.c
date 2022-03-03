/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:03:23 by min-kang          #+#    #+#             */
/*   Updated: 2021/12/20 14:49:09 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_condition(int x, int y)
{
	if (x > FDF_WIN_X && x < FDF_WIN_X + FDF_WIN_SIZE_X
		&& y > FDF_WIN_Y && y < FDF_WIN_Y + FDF_WIN_SIZE_Y)
		return (1);
	return (0);
}

void	vas_y2(t_fdf fdf, t_main main)
{
	int		index;
	t_point	point;
	t_point	to_point;

	index = -1;
	while (++index < main.data.size)
	{
		point = define_point(fdf, main.data.mat_3d[index], main);
		if (draw_condition(point.x, point.y))
			my_mlx_pixel_put(&main.img, point.x, point.y,
				put_color(main.data.max,
					main.data.min, main.data.mat_3d[index].h));
		if (index % main.data.len_line < main.data.len_line - 1)
		{
			to_point = define_point(fdf, main.data.mat_3d[index + 1], main);
			bresenham(main.img, main.data, point, to_point);
		}
		if (index / main.data.len_line < main.data.n_line - 1)
		{
			to_point = define_point(fdf,
					main.data.mat_3d[index + main.data.len_line], main);
			bresenham(main.img, main.data, point, to_point);
		}
	}
	mlx_put_image_to_window(main.vars.mlx, main.vars.win, main.img.img, 0, 0);
}

void	draw_isometric(t_main main)
{
	t_fdf	fdf;

	fdf.size = FDF_WIN_SIZE_Y * 0.4 / (main.data.len_line + main.data.n_line)
		* pow(1.1, main.event.zoom_in_out);
	fdf.start_x = start_x_define(main.data, fdf);
	fdf.start_y = (FDF_WIN_Y + FDF_WIN_SIZE_Y * 0.3);
	vas_y2(fdf, main);
}

void	rotation(t_map *data, t_event *event)
{
	if (event->rotation_x)
	{
		rotate_x(data, event->rotation_x);
		event->rotation_x = 0;
	}
	if (event->rotation_y)
	{
		rotate_y(data, event->rotation_y);
		event->rotation_y = 0;
	}
	if (event->rotation_z)
	{
		rotate_z(data, event->rotation_z);
		event->rotation_z = 0;
	}
}

int	draw_fdf(t_main *main)
{
	if (main->event.re_draw)
	{
		ft_bzero(main->img.addr, 1920 * 1080 * 4);
		if (main->event.rotation_x || main->event.rotation_y
			|| main->event.rotation_z)
			rotation(&main->data, &main->event);
		if (main->event.erase)
		{
			free(main->data.mat_3d);
			main->data.mat_3d = create_3d_matrice(main->data);
			main->event.erase = 0;
		}
		if (main->event.cavalier_on % 2 == 1)
			draw_cavalier(*main);
		else
			draw_isometric(*main);
		main->event.re_draw = 0;
	}
	return (0);
}
