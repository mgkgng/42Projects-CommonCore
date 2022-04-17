/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:20:02 by min-kang          #+#    #+#             */
/*   Updated: 2021/12/19 20:20:04 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	swap_point(t_point *start_p, t_point *end_p)
{
	t_point	swap;

	swap = *start_p;
	*start_p = *end_p;
	*end_p = swap;
}

void	zero_bresenham(t_data img, t_map data, t_point s, t_point e)
{
	int		i;
	int		alt;
	int		temp;

	if (s.y > e.y)
		swap_point(&s, &e);
	i = s.y;
	alt = s.h;
	temp = alt;
	while (i++ < e.y)
	{
		if (e.h - s.h)
			alt = temp + (e.h - s.h)
				* ((float) i - (float) s.y) / ((float) e.y - (float) s.y);
		if (draw_condition(s.x, i))
			my_mlx_pixel_put(&img, s.x, i, put_color(data.max, data.min, alt));
	}
}

void	bresenham_x(t_data img, t_map data, t_point s, t_point e)
{
	int		i;
	float	a;
	float	b;
	int		alt;
	int		temp;

	a = ((float)e.y - (float)s.y) / ((float)e.x - (float)s.x);
	b = s.y - s.x * a;
	if (s.x >= e.x)
		swap_point(&s, &e);
	i = s.x;
	alt = s.h;
	temp = alt;
	while (++i < e.x)
	{
		if (e.h - s.h)
			alt = temp + (e.h - s.h) * ((float) i - (float) s.x)
				/ ((float) e.x - (float) s.x);
		if (draw_condition(i, round(a * i + b)))
			my_mlx_pixel_put(&img, i, roundf(a * i + b),
				put_color(data.max, data.min, alt));
	}
}

void	bresenham_y(t_data img, t_map data, t_point s, t_point e)
{
	int		i;
	float	a;
	float	b;
	int		alt;
	int		temp;

	a = ((float) e.y - (float) s.y) / ((float) e.x - (float) s.x);
	b = s.y - s.x * a;
	if (s.y >= e.y)
		swap_point(&s, &e);
	i = s.y;
	alt = s.h;
	temp = alt;
	while (++i < e.y)
	{
		if (e.h - s.h)
			alt = temp + (e.h - s.h) * ((float) i - (float) s.y)
				/ ((float) e.y - (float) s.y);
		if (draw_condition(roundf(((float) i - (float) b) / (float) a), i))
			my_mlx_pixel_put(&img, round(((float) i - (float) b)
					/ (float) a), i, put_color(data.max, data.min, alt));
	}
}

void	bresenham(t_data img, t_map data, t_point start_p, t_point end_p)
{
	float	a;

	if (end_p.x - start_p.x == 0)
	{
		zero_bresenham(img, data, start_p, end_p);
		return ;
	}
	a = ((float)end_p.y - (float)start_p.y)
		/ ((float)end_p.x - (float)start_p.x);
	if (a < 1 && a > -1)
		bresenham_x(img, data, start_p, end_p);
	else
		bresenham_y(img, data, start_p, end_p);
}
