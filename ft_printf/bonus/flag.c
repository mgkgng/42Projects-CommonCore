/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:24:45 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/02 13:49:48 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	zero(t_print *print, int width)
{
	char	*nov;
	int		i;
	int		j;

	if (ft_strlen(print->s) >= width)
		return ;
	nov = ft_calloc(width + 1, sizeof(char));
	i = 0;
	j = 0;
	if (print->s[0] == '-')
	{
		nov[i++] = '-';
		j++;
	}
	while (i < width - ft_strlen(print->s + j))
		nov[i++] = '0';
	while (print->s[j])
		nov[i++] = print->s[j++];
	nov[i] = '\0';
	free(print->s);
	print->s = nov;
}

void	plus_space(t_print *print, char flag)
{
	char	*nov;
	char	c;
	int		i;
	int		j;

	j = 0;
	if (ft_atoi(print->s) >= 0)
		j++;
	nov = ft_calloc(ft_strlen(print->s) + 1 + j, sizeof(char));
	i = 0;
	if (j)
		nov[i++] = flag;
	while (print->s[++i])
		nov[i + j] = print->s[i];
	nov[i + j] = '\0';
	free(print->s);
	print->s = nov;
}

void	hashtag(t_print *print, int convert)
{
	char	*nov;
	int		i;

	if (ft_strncmp(print->s, "0", ft_strlen(print->s)) == 0)
	{
		free(print->s);
		print->s = ft_strdup("0");
		return ;
	}
	nov = ft_calloc(ft_strlen(print->s) + 3, sizeof(char));
	nov[0] = '0';
	if (convert == CONV_XL)
		nov[1] = 'x';
	else
		nov[1] = 'X';
	i = -1;
	while (print->s[++i])
		nov[i + 2] = print->s[i];
	nov[i + 2] = '\0';
	free(print->s);
	return (nov);
}

void	minus(t_print *print, int width)
{
	char	*nov;
	int		i;

	if (ft_strlen(print->s) >= width)
		return ;
	else
	{
		nov = ft_calloc(width + 1, sizeof(char));
		i = -1;
		while (print->s[++i])
			nov[i] = print->s[i];
		while (i < width)
			nov[i++] = ' ';
	}
	nov[i] = '\0';
	free(print->s);
	print->s = nov;
}

void	app_flag(t_print *print, t_opt opt)
{
	if (!opt.flag && opt.width)
		app_width(print, opt.width);
	if (ft_strchr(opt.flag, '0') && !(ft_strchr(opt.flag, '-')) \
		&& print->type <= CONV_XU && !opt.precis)
		zero(print, opt.width);
	if (ft_strchr(opt.flag, '+') && print->type == CONV_DI)
		plus_space(print, '+');
	if (ft_strchr(opt.flag, ' ') && !ft_strchr(opt.flag, '+') \
		&& (print->type == CONV_DI \
			|| (print->type == CONV_S && !ft_strlen(print->s) && opt.width)))
		plus_space(print, ' ');
	if (ft_strchr(opt.flag, '#') && (print->type == CONV_XL || print->type == CONV_XU))
		hashtag(print, print->type);
	if (ft_strchr(opt.flag, '-'))
		minus(print, opt.width);
}