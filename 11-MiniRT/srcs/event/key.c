/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:55:55 by gphilipp          #+#    #+#             */
/*   Updated: 2022/03/29 12:49:11 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdlib.h>

int	onkeyup(int keycode, t_app *app)
{
	if (keycode == 261)
		app->key_modifier &= ~KEY_MODIFIER_ALT;
	else if (keycode == 257)
		app->key_modifier &= ~KEY_MODIFIER_SHIFT;
	else if (keycode == 256)
		app->key_modifier &= ~KEY_MODIFIER_CTRL;
	else if (keycode == 31)
	{
		app->refresh = 1;
		return (0);
	}
	return (0);
}

int	onkeydown(int keycode, t_app *app)
{
	if (keycode == 261)
		app->key_modifier |= KEY_MODIFIER_ALT;
	else if (keycode == 257)
		app->key_modifier |= KEY_MODIFIER_SHIFT;
	else if (keycode == 256)
		app->key_modifier |= KEY_MODIFIER_CTRL;
	if (keycode == 99)
	{
		app->refresh = 1;
		app->debug = !app->debug;
		return (1);
	}
	if (!(keycode == 53
			|| (app->key_modifier & KEY_MODIFIER_CTRL && keycode == 8)))
		return (0);
	mlx_destroy_window(app->mlx, app->win);
	exit(0);
}
