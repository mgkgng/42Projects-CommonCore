/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:15:53 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/05 12:16:28 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	get_flag(const char *s, int *i)
{
	char	*set;
	int		res;

	res = 1;
	set = ft_strdup("0- #+");
	while (ft_strchr(set, s[*i]))
	{
		if (s[*i] == '-')
			res *= 2;
		else if (s[*i] == '0')
			res *= 3;
		else if (s[*i] == ' ')
			res *= 5;
		else if (s[*i] == '#')
			res *= 7;
		else if (s[*i] == '+')
			res *= 11;
		*i += 1;
	}
	free(set);
	return (res);
}

int	get_width(const char *s, int *i, char **flag)
{
	int	res;

	if (s[*i] == '-')
	{
		if (!ft_strchr(*flag, '-'))
		{
			int x;
			x = 0;
			while (*flag[x])
				x++;
			*flag[x++] = '-';
			*flag[x] = '\0';
		}
		*i += 1;
	}
	res = 0;
	while (ft_isdigit(s[*i]))
	{
		res = res * 10 + (s[*i] - '0');
		*i += 1;
	}
	return (res);
	// pense aux chiffres negatifs
}

int	get_precis(const char *s, int *i)
{
	int	res;
	int	minus;

	if (s[*i] != '.')
		return (0);
	*i += 1;
	if (!ft_isdigit(s[*i]) && s[*i] != '-')
		return (-1);
	if (s[*i] == '-')
	{
		minus = 1;
		*i += 1;
	}
	res = 0;
	while (ft_isdigit(s[*i]))
	{
		res = res * 10 + (s[*i] - '0');
		*i += 1;
	}
	if (!res || minus)
		res = -1;
	return (res);
	// pense aux chiffres negatives, faut ecrire proprement atoi
	// vaut mieux faire directement atoi, puis *i += fonction atoi_len
}

int	*get_instruction(int n, ...)
{
	va_list arg_n;
	int		*ins;
	int		i;

	va_start(arg_n, n);
	ins = ft_calloc(n + 1, sizeof(int));
	i = 0;
	while (i < n)
		ins[i++] = va_arg(arg_n, int);
	ins[i] = 0;
	va_end(arg_n);
	return (ins);
}