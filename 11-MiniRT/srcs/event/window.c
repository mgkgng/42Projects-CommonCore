/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:38:54 by gphilipp          #+#    #+#             */
/*   Updated: 2022/03/29 12:23:52 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdlib.h>

int	onfocuschange(int visible, t_app *app)
{
	app->pause = !visible;
	if (visible)
		app->refresh = 1;
	return (0);
}

int	onvisiblitychange(int visible, t_app *app)
{
	app->pause = !visible;
	if (visible)
		app->refresh = 1;
	return (0);
}

int	onclose(t_app *app)
{
	(void) app;
	exit(0);
	return (0);
}
