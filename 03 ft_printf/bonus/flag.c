/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:24:45 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/04 17:47:01 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	zero(t_print *print, int width)
{
	char	*nov;
	int		i;
	int		j;

	if (ft_strlen(print->str) >= width)
		return ;
	nov = ft_calloc(width + 1, sizeof(char));
	i = 0;
	j = 0;
	if (print->str[0] == '-')
	{
		nov[i++] = '-';
		j++;
	}
	while (i < width - ft_strlen(print->str + j))
		nov[i++] = '0';
	while (print->str[j])
		nov[i++] = print->str[j++];
	nov[i] = '\0';
	free(print->str);
	print->str = nov;
}

void	plus_space(t_print *print, char flag)
{
	char	*nov;
	int		i;
	int		j;

	j = 0;
	if (ft_atoi(print->str) >= 0)
		j++;
	nov = ft_calloc(ft_strlen(print->str) + 1 + j, sizeof(char));
	i = 0;
	if (j)
		nov[i++] = flag;
	while (print->str[++i])
		nov[i + j] = print->str[i];
	nov[i + j] = '\0';
	free(print->str);
	print->str = nov;
}

void	app_flag(t_print *print, t_opt opt)
{
	if (!opt.flag && opt.width)
		return (app_width(print, opt.width));
	else if (!opt.flag)
		return ;
	if (ft_strchr(opt.flag, '0') && !(ft_strchr(opt.flag, '-')) \
		&& print->type <= CONV_XU && !opt.precis)
		zero(print, opt.width);
	if (ft_strchr(opt.flag, '+') && print->type == CONV_DI)
		plus_space(print, '+');
	if (ft_strchr(opt.flag, ' ') && !ft_strchr(opt.flag, '+') \
		&& (print->type == CONV_DI \
			|| (print->type == CONV_S && !ft_strlen(print->str) && opt.width)))
		plus_space(print, ' ');
	if (ft_strchr(opt.flag, '#') && (print->type == CONV_XL || print->type == CONV_XU))
		hashtag(print, print->type);
	if (ft_strchr(opt.flag, '-'))
		minus(print, opt.width);
}