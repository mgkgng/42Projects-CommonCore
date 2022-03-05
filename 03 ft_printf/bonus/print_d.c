/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:42:43 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/05 14:27:45 by min-kang         ###   ########.fr       */
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

int	plus_space(int n, int flag)
{
	char	c;

	if (flag % 7)
		c = '+';
	else
		c = ' ';
	return (ft_putchar(c));
}

int	instruction_d(int n, t_spec spec, int *ins)
{
	int	len;
	int	nbr_len;
	int	i;

	len = 0;
	nbr_len = ft_nbrlen(n);
	i = -1;
	while (ins[++i])
	{
		if (ins[i] == 1)
			len += ft_printnbr(n);
		else if (ins[i] == 2)
			len += print_precis_nbr(spec.precis, nbr_len);
		else if (ins[i] == 3)
			len += width_nbr(spec, n, nbr_len);
		else if (ins[i] == 4)
			len += plus_space(n, spec.flag);
	}
	free(ins);
	return (len);
}

int print_d(int n, t_spec spec)
{
	int	*ins;

	if (!(spec.flag % 2))
	{
		if (n >= 0 && !(spec.flag % 7 && spec.flag % 11))
			ins = get_instruction(4, 4, 2, 1, 3);
		else
			ins = get_instruction(3, 2, 1, 3);
	}
	else
		ins = get_instruction(3, 3, 1, 2);
	return (instruction_d(n, spec, ins));
}

int	print_u(unsigned int n, t_spec spec)
{
	// precision, width
	// flag: '+', '0', '-'
}