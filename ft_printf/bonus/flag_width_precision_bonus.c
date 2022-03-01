/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_width_precision_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:15:53 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/01 19:50:23 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*get_flag(const char *s, int *i)
{
	char	*fl;
	int		a;
	char	*res;

	a = 0;
	fl = ft_strdup("0- #+");
	if (!ft_strchr(fl, s[*i]))
	{
		free(fl);
		return (NULL);
	}
	res = ft_calloc(6, sizeof(char));
	while (ft_strchr(fl, s[*i]))
		res[a++] = s[*i++];
	res[a] = '\0';
	free(fl);
	return (res);
}

int	get_width(const char *s, int *i)
{
	int	res;

	while (ft_isdigit(s[*i]))
		res = res * 10 + (s[*i++] - '0');
	return (res);
}

int	get_precis(const char *s, int *i)
{
	int	res;

	if (s[*i] != '.')
		return (0);
	if (!ft_isdigit(s[++*i]))
		return (-1);
	while (ft_isdigit(s[*i]))
		res = res * 10 + (s[*i++] - '0');
	if (!res)
		res = -1;
	return (res);
}

char	*only_width(char *arg, int width_min)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ft_strlen(arg) >= width_min)
		return (arg);
	res = ft_calloc(width_min + 1, sizeof(char));
	while (i < width_min - ft_strlen(arg))
		res[i++] = ' ';
	while (arg[j])
		res[i++] = arg[j++];
	res[i] = '\0';
	ft_putstr(res);
	if (!ft_strlen(arg)) // wtf??
		ft_putchar('\0');
	free(arg);
	return (res);
}
