/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:01:29 by min-kang          #+#    #+#             */
/*   Updated: 2021/12/19 20:06:54 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define CSTART_R 26
#define CSTART_G 42
#define CSTART_B 108
#define CMIDDLE_R 178
#define CMIDDLE_G 31
#define CMIDDLE_B 31
#define CEND_R 253
#define CEND_G 187
#define CEND_B 45

int	max_find(t_map data)
{
	int	i;
	int	max;

	i = -1;
	max = 0;
	while (++i < data.size)
		if (data.mat_3d[i].z > max)
			max = data.mat_3d[i].z;
	return (max);
}

int	put_color(int max, int min, int alt)
{
	int		result;
	float	x;
	t_color	color;
	float	half;

	x = ((float) alt - (float) min) / ((float) max - (float) min);
	half = ((float) max - (float) min) / 2;
	if (x <= 0.5)
	{
		x = ((float) alt - (float) min) / half;
		color.r = CSTART_R + (int) round((CMIDDLE_R - CSTART_R) * x);
		color.g = CSTART_G + (int) round((CMIDDLE_G - CSTART_G) * x);
		color.b = CSTART_B + (int) round((CMIDDLE_B - CSTART_B) * x);
	}
	else
	{
		x = ((float) alt - half) / half;
		color.r = CMIDDLE_R + (int) round((CEND_R - CMIDDLE_R) * x);
		color.g = CMIDDLE_G + (int) round((CEND_G - CMIDDLE_G) * x);
		color.b = CMIDDLE_B + (int) round((CEND_B - CMIDDLE_B) * x);
	}
	result = (0 << 24) | (color.r << 16) | (color.g << 8) | color.b;
	return (result);
}
