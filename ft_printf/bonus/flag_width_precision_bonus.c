/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_width_precision_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:15:53 by min-kang          #+#    #+#             */
/*   Updated: 2021/11/15 18:15:57 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_flag	*ft_flag(const char *s, int i)
{
	char	*fl;
	int		index;
	t_flag	*result;

	index = 0;
	fl = ft_strdup("0- #+");
	result = ft_calloc(1, sizeof(t_flag));
	if (!ft_strchr(fl, s[i]))
	{
		free(fl);
		return (result);
	}
	result->flags = malloc(6);
	while (ft_strchr(fl, s[i]))
		result->flags[index++] = s[i++];
	result->flags[index] = '\0';
	result->index = i;
	free(fl);
	return (result);
}

t_wp	*ft_width_min(const char *s, int i, t_wp *s_wp)
{
	while (ft_isdigit(s[i]))
		s_wp->w_value = s_wp->w_value * 10 + (s[i++] - '0');
	s_wp->w_index = i;
	return (s_wp);
}

t_wp	*ft_precision(const char *s, int i, t_wp *s_wp)
{
	if (s[i++] != '.')
		return (s_wp);
	if (!ft_isdigit(s[i]))
	{
		s_wp->p_value = -1;
		s_wp->p_index = i;
		return (s_wp);
	}
	else
		while (ft_isdigit(s[i]))
			s_wp->p_value = s_wp->p_value * 10 + (s[i++] - '0');
	if (s_wp->p_value == 0)
		s_wp->p_value = -1;
	s_wp->p_index = i;
	return (s_wp);
}

char	*only_width_min(char *arg, int width_min)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ft_strlen(arg) >= (size_t) width_min)
		return (arg);
	result = malloc(width_min + 1);
	while (i < width_min - (int) ft_strlen(arg))
		result[i++] = ' ';
	while (arg[j])
		result[i++] = arg[j++];
	result[i] = '\0';
	ft_putstr(result);
	if (!ft_strlen(arg))
		ft_putchar('\0');
	free(arg);
	return (result);
}
