/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:44:50 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/05 14:18:42 by min-kang         ###   ########.fr       */
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
	int	nbr_len;
	int	i;

	len = 0;
	nbr_len = ft_nbrlen(n);
	if (nbr_len < spec.precis)
		nbr_len = spec.precis;
	i = -1;
	while (ins[++i])
	{
		if (ins[i] == 1)
			len += ft_printhex(n, spec.precis, upper);
		else if (ins[i] == 2)
			len += width_hex(spec, nbr_len, upper);
		else if (ins[i] == 3)
			len += print_hashtag(upper);
	}
	free(ins);
	return (len);
}

int	print_x(unsigned int n, t_spec spec, int upper)
{
	int	*ins;

	if (!(spec.flag % 2))
	{
		if (!(spec.flag % 7))
			ins = get_instruction(3, 3, 1, 2);
		else
			ins = get_instruction(2, 1, 2);
	}
	else
		ins = get_instruction(2, 2, 1);
	return (instruction_x(n, spec, upper, ins));	
}