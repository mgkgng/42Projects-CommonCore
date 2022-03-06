/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:33:07 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/06 11:38:56 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	width_unsigned(t_spec spec, int nbr_len)
{
	int		len;

	len = 0;
	if (spec.flag % 2 && !(spec.flag % 3)
		&& (spec.precis <= nbr_len || spec.width < spec.precis))
		len += print_width(spec.width, nbr_len, '0');
	else
		len += print_width(spec.width, nbr_len, ' ');
	return (len);
}

int	width_nbr(t_spec spec, int n, int nbr_len)
{
	int		len;

	/*if (!spec.width)
		return (0);*/
	len = 0;
	if (n >= 0 && !(spec.flag % 7 && spec.flag % 11))
		spec.width--;
	if (spec.flag % 2 && !(spec.flag % 3)
		&& (spec.precis <= nbr_len || spec.width < spec.precis))
	{
		if (n >= 0 && !(spec.flag % 7 && spec.flag % 11))
			plus_space(spec.flag);
		len += print_width(spec.width, nbr_len, '0');
	}
	else
	{
		len += print_width(spec.width, nbr_len, ' ');
		if (n >= 0 && !(spec.flag % 7 && spec.flag % 11))
			plus_space(spec.flag);
	}
	return (len);
}

int	width_hex(t_spec spec, unsigned int n, int upper)
{
	int		len;
	int		nbr_len;

	len = 0;
	nbr_len = print_nbr_len(n, spec, 16);
	if (!(spec.flag % 7) && n && spec.precis)
		spec.width -= 2;
	if (spec.flag % 2 && !(spec.flag % 3)
		&& (spec.precis <= nbr_len || spec.width < spec.precis))
	{
		if (!(spec.flag % 7) && n && spec.precis)
			len += hashtag(upper);
		len += print_width(spec.width, nbr_len, '0');
	}
	else
	{
		len += print_width(spec.width, nbr_len, ' ');
		if (spec.flag % 2 && !(spec.flag % 7) && n && spec.precis)
			len += hashtag(upper);
	}
	return (len);
}

int	print_width(int width, int len, char c)
{
	int	i;

	//printf("width==%d len==%d", width, len);
	if (len >= width)
		return (0);
	i = -1;
	while (++i < width - len)
		ft_putchar(c);
	return (i);
}