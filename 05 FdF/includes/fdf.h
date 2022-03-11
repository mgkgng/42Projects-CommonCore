/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:03:31 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/11 11:28:46 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "key.h"
# include <stdio.h>
# include "design.h"
# include <errno.h>
# include <string.h>
# include <unistd.h>

typedef struct s_3d{
	float	x;
	float	y;
	float	z;
	int		h;
}	t_3d;

typedef struct s_img{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_vars{
	void	*mlx;
	void	*win;
	t_img	fdf;
}				t_vars;

typedef struct s_map{
	int		**mat_2d;
	int		n_line;
	int		len_line;
	int		max;
	int		min;
	t_3d	*mat_3d;
	int		size;
}	t_map;

typedef struct s_point{
	int	x;
	int	y;
	int	h;
}	t_point;

typedef struct s_color{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color;

typedef struct s_fdf{
	int		start_x;
	int		start_y;
	float	size;
}	t_fdf;

typedef struct s_event{
	int	rotation_x;
	int	rotation_y;
	int	rotation_z;
	int	move_up_down;
	int	move_right_light;
	int	zoom_in_out;
	int	re_draw;
	int	cavalier_on;
	int	erase;
}	t_event;

typedef struct s_main{
	t_vars	vars;
	t_img	img;
	t_data	data;
	t_event	event;
}	t_main;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		draw_fdf(t_main *main);
t_map	data_2d_matrice(int fd);
int		put_color(int max, int min, int alt);
int		max_find(t_map data);
void	draw_square(t_data img, int line_width);
int		draw_condition(int x, int y);
void	rotate_x(t_map *data, int direction);
void	rotate_y(t_map *data, int direction);
void	rotate_z(t_map *data, int direction);
int		square_color(int i, int size);
void	draw_cavalier(t_main main);
void	bresenham(t_data img, t_map data, t_point start_p, t_point end_p);
int		start_x_define(t_map data, t_fdf fdf);
t_3d	*create_3d_matrice(t_map data);
void	rotation(t_map *data, t_event *event);
int		error_check(char ***data, int size);
int		nl_count(char *s);
int		size_count(char **s);
void	swap_point(t_point *start_p, t_point *end_p);
void	zero_bresenham(t_data img, t_map data, t_point s, t_point e);
void	bresenham_x(t_data img, t_map data, t_point s, t_point e);
void	bresenham(t_data img, t_map data, t_point start_p, t_point end_p);
t_point	define_point(t_fdf fdf, t_3d point, t_main main);
int		start_x_define(t_map data, t_fdf fdf);
void	ft_putchar(char c);
void	ft_putstr(char *s);
int		max_find(t_map data);
int		min_find(t_map data);
int		error(int code);

/* parse */
t_map	parse(int fd);

#endif
