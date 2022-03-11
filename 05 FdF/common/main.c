/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:50:13 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/11 11:27:46 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_initialise(t_main main)
{
	
}

int	main(int argc, char **argv)
{
	t_main	main;
	t_map	map;
	int		fd;

	if (argc != 2)
		return (error(1));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (error(2));
	map = parse(fd);
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