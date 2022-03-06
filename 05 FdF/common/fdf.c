/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:03:09 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/06 11:51:26 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	move_event(int keycode, t_event *event)
{
	if (keycode == MOVE_UP)
		event->move_up_down += 1;
	if (keycode == MOVE_DOWN)
		event->move_up_down -= 1;
	if (keycode == MOVE_LEFT)
		event->move_right_light -= 1;
	if (keycode == MOVE_RIGHT)
		event->move_right_light += 1;
}

void	rotation_event(int keycode, t_event *event)
{
	if (keycode == ROTATE_X_DOWN)
		event->rotation_x -= 1;
	if (keycode == ROTATE_X_UP)
		event->rotation_x += 1;
	if (keycode == ROTATE_Y_LEFT)
		event->rotation_y -= 1;
	if (keycode == ROTATE_Y_RIGHT)
		event->rotation_y += 1;
	if (keycode == ROTATE_Z_LEFT)
		event->rotation_z -= 1;
	if (keycode == ROTATE_Z_RIGHT)
		event->rotation_z += 1;
}

int	key_event(int keycode, t_event *event)
{
	if (keycode == EXIT)
		exit(0);
	if (keycode == MOVE_UP || keycode == MOVE_DOWN || keycode == MOVE_LEFT
		|| keycode == MOVE_RIGHT)
		move_event(keycode, event);
	if (keycode == ROTATE_X_DOWN || keycode == ROTATE_X_UP
		|| keycode == ROTATE_Y_LEFT || keycode == ROTATE_Y_RIGHT
		|| keycode == ROTATE_Z_LEFT || keycode == ROTATE_Z_RIGHT)
		rotation_event(keycode, event);
	if (keycode == ZOOM_IN)
		event->zoom_in_out += 1;
	if (keycode == ZOOM_OUT)
		event->zoom_in_out -= 1;
	if ((keycode == 83 && event->cavalier_on % 2 == 0)
		|| (keycode == 82 && event->cavalier_on % 2 == 1))
	{
		event->cavalier_on += 1;
		event->erase = 1;
	}
	event->re_draw = 1;
	return (0);
}