/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 08:56:58 by gphilipp          #+#    #+#             */
/*   Updated: 2022/03/29 12:28:04 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "color.h"
# include "libx.h"
# include "dep.h"
# include "point.h"

# define WIDTH			1280
# define HEIGHT			800

typedef unsigned char	t_uchar;

typedef struct s_app
{
	t_mlx			*mlx;
	t_win			*win;
	int				refresh;
	int				pause;
	int				debug;
	int				key_modifier;
}			t_app;

/*
** GUI_FLAG
*/
enum {
	GUI_NONE = 0x00,
	GUI_DRAW = 0x01,
	GUI_POST = 0x02
};

/*
** KEY_MODIFIER
*/
enum {
	KEY_MODIFIER_ALT = 0x01,
	KEY_MODIFIER_CTRL = 0x02,
	KEY_MODIFIER_SHIFT = 0x04
};

/* event */

/* key */
int			onkeyup(int keycode, t_app *app);
int			onkeydown(int keycode, t_app *app);

/* window */
int			onfocuschange(int visible, t_app *app);
int			onvisiblitychange(int visible, t_app *app);
int			onclose(t_app *app);

#endif
