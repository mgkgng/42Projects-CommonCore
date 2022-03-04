/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_diu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:42:43 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/04 22:14:58 by min-kang         ###   ########.fr       */
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

int	print_precis_nbr(int precis, int len)
{
	int	i;

	i = 0;
	while (len + i++ < precis)
		ft_putchar('0');
	return (i);
}
// got an idea

int	distribution(int n, t_spec spec, int flag)
{
	int	len;

	if (!flag)
		return (ft_printnbr(n));
	if (flag == 1)
	{

	}
	if (flag == 2) // width -> space
	{
		
	}
}

int print_d(int n, t_spec spec)
{
	int	len;

	len = 0;
	if (spec.width)
	{
		if (!(spec.flag % 11) && n >= 0)
			len += ft_putchar('+');
		else if (!(spec.flag % 5) && n >= 0)
			len += ft_putchar(' ');
		if (spec.precis != -1)
			len += print_precis_nbr(spec.precis, ft_nbrlen(n, 10) + len);
	// precision, width
	if (!(spec.flag % 2) && spec.flag % 3) // '-'
	{}
	else if (!(spec.flag % 3)) // '0'
	{}
	if (!(spec.flag % 11)) // '+'

	if (!(spec.flag % 5)) // ' '
	// flag: '+', '0', ' ', '-'
}

int	print_u(unsigned int n, t_spec spec)
{
	// precision, width
	// flag: '+', '0', '-'
}