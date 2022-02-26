/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_machine_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:23:48 by min-kang          #+#    #+#             */
/*   Updated: 2021/11/17 14:32:46 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_value	*print_factory(int i, const char *s, va_list arg_n)
{
	t_flag	*s_flag;
	t_wp	*s_wp;
	t_arg	*arg;
	t_value	*result;

	s_flag = ft_flag(s, ++i);
	if (s_flag->flags)
		i = s_flag->index;
	s_wp = ft_calloc(1, sizeof(t_wp));
	s_wp = ft_width_min(s, i, s_wp);
	if (s_wp->w_value)
		i = s_wp->w_index;
	s_wp = ft_precision(s, i, s_wp);
	if (s_wp->p_value)
		i = s_wp->p_index;
	arg = malloc(sizeof(t_arg));
	result = malloc(sizeof(t_value));
	result->value = 0;
	arg = ft_conversion(s[i], arg, result, arg_n);
	result->value = print_and_return(arg->data, arg->type, s_flag->flags, s_wp);
	result->index = i + 1;
	free(arg);
	free(s_flag);
	free(s_wp);
	return (result);
}

t_arg	*ft_conversion(char convert, t_arg *arg, t_value *result, va_list arg_n)
{
	if (convert == 'd' || convert == 'i')
		arg->data = ft_itoa(va_arg(arg_n, int));
	else if (convert == 'u')
		arg->data = ft_itoa(va_arg(arg_n, unsigned int));
	else if (convert == 'x')
		arg->data = ft_itoa_base((unsigned int) va_arg(arg_n, int), \
			"0123456789abcdef");
	else if (convert == 'X')
		arg->data = ft_itoa_base((unsigned int) va_arg(arg_n, int), \
			"0123456789ABCDEF");
	else if (convert == 'c')
		arg->data = char_to_string(va_arg(arg_n, int));
	else if (convert == 's')
		arg->data = ft_strdup_printf(va_arg(arg_n, char *));
	else if (convert == 'p')
	{
		arg->data = ft_ltoa_base((unsigned long int) va_arg(arg_n, void *), \
			"0123456789abcdef");
		arg->data = ft_strjoin("0x", arg->data);
		result->value += 2;
	}
	else if (convert == '%')
		arg->data = char_to_string('%');
	arg->type = convert;
	return (arg);
}

int	print_and_return(char *arg, char convert, char *flags, t_wp *s_wp)
{
	int		len;

	if (!flags && !s_wp->w_value && !s_wp->p_value)
		return (make_it_shorter(arg, convert));
	arg = precision_app(arg, convert, s_wp->p_value);
	len = 0;
	if (convert == 'c' && !ft_strlen(arg))
	{
		if (s_wp->w_value)
			s_wp->w_value--;
		len++;
	}
	arg = flag_converter(arg, convert, flags, s_wp);
	len += ft_strlen(arg);
	free(arg);
	free(flags);
	return (len);
}

char	*flag_converter(char *arg, char convert, char *flags, t_wp *s_wp)
{
	char	*set;

	if (!flags && s_wp->w_value)
	{
		arg = only_width_min(arg, s_wp->w_value);
		//ft_putstr(arg);
		return (arg);
	}
	set = ft_strdup("diuxX");
	if (ft_strchr(flags, '0') && !(ft_strchr(flags, '-')) \
		&& ft_strchr(set, convert) && !s_wp->p_value)
		arg = zero_flag(arg, s_wp->w_value);
	if (ft_strchr(flags, '+') && (convert == 'd' || convert == 'i'))
		arg = plus_flag(arg);
	if (ft_strchr(flags, ' ') && !ft_strchr(flags, '+') \
		&& (convert == 'd' || convert == 'i' \
			|| (convert == 's' && !ft_strlen(arg) && s_wp->w_value)))
		arg = space_flag(arg);
	if (ft_strchr(flags, '#') && (convert == 'x' || convert == 'X'))
		arg = hashtag_flag(arg, convert);
	if (ft_strchr(flags, '-'))
		arg = minus_flag(arg, s_wp->w_value);
	ft_putstr(arg);
	free(set);
	return (arg);
}

int	make_it_shorter(char *arg, char convert)
{
	int	result;

	if (convert == 'c' && !ft_strlen(arg))
	{
		ft_putchar('\0');
		result = 1;
	}
	else
	{
		ft_putstr(arg);
		result = ft_strlen(arg);
	}
	free(arg);
	return (result);
}
