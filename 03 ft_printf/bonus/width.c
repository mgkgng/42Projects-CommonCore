/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:34:20 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/03 15:55:33 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	app_width(t_print *print, int width)
{
	char	*nov;
	int		i;
	int		j;


	if (ft_strlen(print->str) >= width)
		return ;
	nov = ft_calloc(width + 1, sizeof(char));
	i = 0;
	while (i < width - ft_strlen(print->str))
		nov[i++] = ' ';
	j = 0;
	while (print->str[j])
		nov[i++] = print->str[j++];
	if (print->str[0] == '\0' && print->type == CONV_C)
		nov[i - 1] = '\0';
	nov[i] = '\0';
	free(print->str);
	print->str = nov;
}
