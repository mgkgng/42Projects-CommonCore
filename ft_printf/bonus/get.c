/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:15:53 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/02 14:12:17 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*get_flag(const char *s, int *i)
{
	char	*set;
	int		a;
	char	*res;

	a = 0;
	set = ft_strdup("0- #+");
	if (!ft_strchr(set, s[*i]))
	{
		free(set);
		return (NULL);
	}
	res = ft_calloc(6, sizeof(char));
	while (ft_strchr(set, s[*i]))
		res[a++] = s[*i++];
	res[a] = '\0';
	free(set);
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

char	*get_str(char type, va_list arg_n)
{	
	if (type == 'd' || type == 'i')
		return (ft_itoa(va_arg(arg_n, int)));
	else if (type == 'u')
		return (ft_itoa(va_arg(arg_n, unsigned int)));
	else if (type == 'x')
		return (ft_itoa_base((unsigned int) va_arg(arg_n, int), 0));
	else if (type == 'X')
		return (ft_itoa_base((unsigned int) va_arg(arg_n, int), 1));
	else if (type == 'c')
		return (to_string(va_arg(arg_n, int)));
	else if (type == 's')
		return (ft_strdup_printf(va_arg(arg_n, char *)));
	else if (type == 'p')
		return (get_pointer((unsigned long int) va_arg(arg_n, void *)));
	else if (type == '%')
		return (to_string('%'));
	/* think about ELSE
	else
		return (NULL);
		->
		if (!arg)
			return (0);
	*/
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
}