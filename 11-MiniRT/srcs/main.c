/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 08:29:19 by gphilipp          #+#    #+#             */
/*   Updated: 2022/03/31 19:59:01 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	draw_raytraycing(t_img *img)
{
	int				*dpixel;
	int				i;
	t_point			pos;

	i = 0;
	while (i < img->width * img->height)
	{
		pos = (t_point){i % img->width + 1, i / img->width + 1};
		dpixel = ((int *)img->buffer) + i;
		*dpixel = GREEN;
		i++;
	}
}

void	raytraycing(t_app *app, int flag)
{
	static t_img	*img = 0;

	if (!img)
	{
		img = mlx_new_image(app->mlx, WIDTH, HEIGHT);
		flag |= GUI_DRAW;
	}
	if (flag & GUI_DRAW)
	{
		draw_raytraycing(img);
	}	
	if (flag & GUI_POST)
		mlx_put_image_to_window(app->win, img, 0, 0);
}

int	render_frame(t_app *app)
{
	int			flag;

	flag = GUI_NONE;
	if (app->refresh)
		flag |= GUI_DRAW | GUI_POST;
	raytraycing(app, flag);
	app->refresh = 0;
	return (0);
}

int	minirt(int argc, char const *argv[])
{
	t_app			app;

	(void) argc;
	(void) argv;
	app.mlx = mlx_init();
	app.win = mlx_new_window(app.mlx, WIDTH, HEIGHT, "minRT");
	app.refresh = 1;
	app.pause = 0;
	app.debug = 0;
	app.key_modifier = 0;
	mlx_do_key_autorepeatoff(app.mlx);
	mlx_hook(app.win, ON_KEYUP, onkeyup, &app);
	mlx_hook(app.win, ON_KEYDOWN, onkeydown, &app);
	mlx_hook(app.win, ON_FOCUSCHANGE, onfocuschange, &app);
	mlx_hook(app.win, ON_VISIBILITYCHANGE, onvisiblitychange, &app);
	mlx_hook(app.win, ON_DESTROY, onclose, &app);
	mlx_loop_hook(app.mlx, 86400000, render_frame, &app);
	mlx_loop(app.mlx);
	return (0);
}

int	main(int argc, char const *argv[])
{
	return (minirt(argc - 1, &argv[1]));
}
