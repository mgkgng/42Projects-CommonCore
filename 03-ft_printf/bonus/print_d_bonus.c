/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:42:43 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/17 16:33:25 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	plus_space(int flag)
{
	char	c;

	if (!(flag % 7))
		c = '+';
	else
		c = ' ';
	return (ft_putchar(c));
}

int	instruction_d(long long int n, t_spec spec, int *ins)
{
	int	len;
	int	nbr_len;
	int	i;

	len = 0;
	nbr_len = print_nbr_len(n, spec, 10);
	i = -1;
	while (ins[++i])
	{
		if (ins[i] == 1)
			len += print_nbr(&n, spec);
		else if (ins[i] == 2)
			len += width_nbr(spec, &n, nbr_len);
		else if (ins[i] == 3)
			len += plus_space(spec.flag);
	}
	free(ins);
	return (len);
}

int	print_d(int n, t_spec spec)
{
	int				*ins;

	if (!(spec.flag % 2))
	{
		if (n >= 0 && !(spec.flag % 7 && spec.flag % 11))
			ins = get_instruction(3, 3, 1, 2);
		else
			ins = get_instruction(2, 1, 2);
	}
	else
		ins = get_instruction(2, 2, 1);
	return (instruction_d(n, spec, ins));
}
