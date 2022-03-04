/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:44:50 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/04 18:21:07 by min-kang         ###   ########.fr       */
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

int	print_hashtag(int flag)
{
	if (!flag)
		ft_putstr("0x");
	else
		ft_putstr("0X");
	return (2);
}

int	print_x(unsigned int n, t_spec spec, int flag)
{
	int	len;

	len = 0;
	if (spec.width)
	{
		if ()
		
	}
	else
	{
		
	}
// precision, width
//flag = '0', '#', '-'


}