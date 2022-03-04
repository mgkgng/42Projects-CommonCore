/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:15:53 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/04 18:16:22 by min-kang         ###   ########.fr       */
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

char	*get_str(char type, va_list arg_n)
{	
	if (type == 'd' || type == 'i')
		return (ft_itoa(va_arg(arg_n, int)));
	else if (type == 'u')
		return (ft_itoa(va_arg(arg_n, unsigned int)));
	else if (type == 'x')
		return (hex((unsigned int) va_arg(arg_n, int), 0));
	else if (type == 'X')
		return (hex((unsigned int) va_arg(arg_n, int), 1));
	else if (type == 'c')
		return (to_string(va_arg(arg_n, int)));
	else if (type == 's')
		return (dup_string(va_arg(arg_n, char *)));
	else if (type == 'p')
		return (get_pointer((unsigned long int) va_arg(arg_n, void *)));
	else if (type == '%')
		return (to_string('%'));
	else
		return (NULL);
}

int	get_type(char type)
{
	if (type == 'd' || type == 'i')
		return (CONV_DI);
	else if (type == 'u')
		return (CONV_U);
	else if (type == 'x')
		return (CONV_XL);
	else if (type == 'X')
		return (CONV_XU);
	else if (type == 's')
		return (CONV_S);
	else if (type == 'c')
		return (CONV_C);
	else if (type == 'p')
		return (CONV_P);
	else if (type == '%')
		return (CONV_PERC);
	else
		return (-1);
}