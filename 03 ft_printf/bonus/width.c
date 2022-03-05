/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:33:07 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/05 13:50:19 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	width_nbr(t_spec spec, int nbr_len)
{
	char	c;
	int		len;

	len = 0;
	if (spec.flag % 2 && !(spec.flag % 3)
		&& (spec.precis <= nbr_len || spec.width < spec.precis))
			len += print_width(spec.width, nbr_len, '0');
	else
		len += print_width(spec.width, nbr_len, ' ');
	return (len);
}

int	width_hex(int len, t_spec spec, int upper)
{
	char	c;
	int		res;

	res = 0;
	if (!(spec.flag % 7))
		spec.width -= 2;
	if (spec.flag % 2 && !(spec.flag % 3)
		&& (spec.precis <= len || spec.width < spec.precis))
	{
			if (!(spec.flag % 7))
				res += print_hashtag(upper);
			res += print_width(spec.width, len, '0');
	}
	else
	{
		res += print_width(spec.width, len, ' ');
		if (spec.flag % 2 && !(spec.flag % 7))
			res += print_hashtag(upper);
	}
	return (res);
}

int	print_width(int width, int len, char c)
{
	int	i;

	if (len >= width)
		return (0);
	i = 0;
	while (i++ < width - len)
		ft_putchar(c);
	return (i);
}