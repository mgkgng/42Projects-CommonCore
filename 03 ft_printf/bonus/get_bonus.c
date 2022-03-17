/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:15:53 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/17 18:04:52 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	skip_space(const char *s, int *i)
{
	while (s[*i] && s[*i] == ' ')
		(*i)++;
}

int	get_flag(const char *s, int *i)
{
	char	*set;
	int		res;

	res = 1;
	set = ft_strdup("0- #+");
	while (s[*i] && ft_strchr(set, s[*i]))
	{
		if (s[*i] == '-' && res % 2)
			res *= 2;
		else if (s[*i] == '0' && res % 3)
			res *= 3;
		else if (s[*i] == '#' && res % 5)
			res *= 5;
		else if (s[*i] == '+' && res % 7)
			res *= 7;
		else if (s[*i] == ' ' && res % 11)
			res *= 11;
		(*i)++;
	}
	free(set);
	return (res);
}

int	get_width(const char *s, int *i, int *flag)
{
	int	res;

	if (!ft_isdigit(s[*i]) && s[*i] != '-')
		return (0);
	res = ft_atoi(s + *i);
	if (res < 0)
	{
		res *= -1;
		*flag *= 2;
	}
	*i += ft_nbrlen(res, 10);
	skip_space(s, i);
	return (res);
}

int	get_precis(const char *s, int *i)
{
	int	res;

	if (s[*i] != '.')
		return (-1);
	*i += 1;
	if (!ft_isdigit(s[*i]) && s[*i] != '-')
		return (0);
	res = ft_atoi(s + *i);
	*i += ft_nbrlen(res, 10);
	if (res < 0)
		res = -1;
	skip_space(s, i);
	return (res);
}

int	*get_instruction(int n, ...)
{
	va_list	arg_n;
	int		*ins;
	int		i;

	va_start(arg_n, n);
	ins = malloc(sizeof(int) * (n + 1));
	i = 0;
	while (i < n)
		ins[i++] = va_arg(arg_n, int);
	ins[i] = 0;
	va_end(arg_n);
	return (ins);
}
