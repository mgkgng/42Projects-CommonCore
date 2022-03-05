/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:29:38 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/05 15:20:20 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	instruction_u(unsigned int n, t_spec spec, int *ins)
{
	int len;
	int	nbr_len;
	int	i;

	len = 0;
	nbr_len = ft_nbrlen(n, 10);
	i = -1;
	while (ins[++i])
	{
		if (ins[i] == 1)
			len += ft_printnbr(n);
		else if (ins[i] == 2)
			len += print_precis_nbr(spec.precis, nbr_len);
		else
			len += width_unsigned(spec, nbr_len);
	}
	free(ins);
	return (len);
}

int	print_u(unsigned int n, t_spec spec)
{
	int	*ins;

	if (!(spec.flag % 2))
		ins = get_instruction(3, 2, 1, 3);
	else
		ins = get_instruction(3, 3, 2, 1);
	return (instruction_u(n, spec, ins));
}