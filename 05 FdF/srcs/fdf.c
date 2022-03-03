/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:03:09 by min-kang          #+#    #+#             */
/*   Updated: 2021/12/20 14:57:00 by min-kang         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_main	main;
	int		fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	main.data = data_2d_matrice(fd);
	main.vars.mlx = mlx_init();
	main.vars.win = mlx_new_window(main.vars.mlx, 1920, 1080, "FdF");
	main.img.img = mlx_new_image(main.vars.mlx, 1920, 1080);
	main.img.addr = mlx_get_data_addr(main.img.img, \
			&main.img.bits_per_pixel, &main.img.line_len, &main.img.endian);
	ft_bzero(&main.event, sizeof(main.event));
	main.event.re_draw = 1;
	mlx_hook(main.vars.win, 2, 1L << 0, key_event, &main.event);
	draw_fdf(&main);
	mlx_loop_hook(main.vars.mlx, draw_fdf, &main);
	mlx_loop(main.vars.mlx);
	close(fd);
	return (0);
}
