/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:41:48 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/04 17:53:12 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_ptrlen(unsigned long long n, t_spec spec)
{
	int	len;

	len = 3;
	while (n > 15)
	{
		n /= 16;
		len++;
	}
	if (len < spec.precis)
		return (spec.precis);
	return (len);
}

void	ft_printptr(unsigned long long n, t_spec spec, int flag)
{
	int		len;
	char	*set;

	set = ft_strdup("0123456789abcdef");

	len = ft_putstr("0x");
	if (n > 16)
		ft_printptr(n / 16, spec, 0);
	ft_putchar(set[n % 16]);
	free(set);
}

int	print_p(unsigned long long n, t_spec spec)
{
	int	len;

	if (spec.width > len)
	{
		if (ft_strchr(spec.flag, '-')) {}
			
		ft_printptr(n, spec, 1);
		if (!ft_strchr(spec.flag, '-')) {}
			
	}
	return (len);
}