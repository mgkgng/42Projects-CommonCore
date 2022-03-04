/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:42:43 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/04 17:54:35 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printnbr(long long int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
		ft_printnbr(n / 10);
	ft_putchar(n % 10 + '0');
	return (ft_nbrlen(n, 10));
}

int print_d(int n, t_spec spec)
{
	// precision, width
	// flag: '+', '0', ' ', '-'
}

int	print_u(unsigned int n, t_spec spec)
{
	// precision, width
	// flag: '+', '0', '-'
}