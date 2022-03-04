/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:40:46 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/04 22:01:35 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_c(int c, t_spec spec)
{
	int	len;
	
	len = 0;
	if (spec.width)
	{
		if (!(spec.flag % 2))
			ft_putchar(c);
		len += print_width(spec.width, 1);
		if ((spec.flag % 2))
			ft_putchar(c);
	}
	else
		ft_putchar(c);
	return (++len);
}
