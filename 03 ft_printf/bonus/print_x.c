/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:44:50 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/05 13:30:26 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_pow(int nb, int pow)
{
	if (!pow)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

int	ft_printhex(unsigned int n, int precis, int flag)
{
	int				i;
	char			*set;
	int				len;	

	if (!flag)
		set = ft_strdup("0123456789abcdef");
	else
		set = ft_strdup("0123456789ABCDEF");
	len = ft_nbrlen((long long int) n, 16);
	i = len;
	while (len++ < precis)
		ft_putchar('0');
	while (--i)
	{
		ft_putchar(set[n / 16 * ft_pow(16, i)]);
		n %= ft_pow(16, i);
	}
	return (len);
}

int	print_hashtag(int upper)
{
	if (!upper)
		ft_putstr("0x");
	else
		ft_putstr("0X");
	return (2);
}

int	instruction_x(unsigned int n, t_spec spec, int upper, int *ins)
{
	int	len;
	int	i;
	int	tmp;

	len = 0;
	i = -1;
	if (ft_nbrlen(n) >= spec.precis)
		tmp = ft_nbrlen(n);
	else
		tmp = spec.precis;
	while (ins[++i])
	{
		if (ins[i] == 1)
			len += ft_printhex(n, spec.precis, upper);
		else if (ins[i] == 2)
			len += width_x(tmp, spec, upper);
	}
	free(ins);
	return (len);
}

int	width_x(int len, t_spec spec, int upper)
{
	char	c;
	int		res;

	res = 0;
	if (!(spec.flag % 7))
		spec.width -= 2;
	if (spec.flag % 2 && !(spec.flag % 3)
		&& (spec.precis <= len || spec.width < spec.precis))
	{
		{
			if (!(spec.flag % 7))
				res += print_hashtag(upper);
			res += print_width(spec.width, len, '0');
		}
	}
	else
	{
		res += print_width(spec.width, len, ' ');
		if (!(spec.flag % 7))
			res += print_hashtag(upper);
	}
	return (res);
}

int	print_x(unsigned int n, t_spec spec, int upper)
{
	int	*ins;

	// precision, width
	// if 0
		// width > precision > 0
			// space -> zero
		// !precision || width < precision
			// zero
		// width < precision
			// zero
	// '0', '-', '#'
}