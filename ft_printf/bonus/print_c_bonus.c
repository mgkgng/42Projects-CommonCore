/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:40:46 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/17 16:33:23 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	instruction_c(int c, t_spec spec, int *ins)
{
	int	i;
	int	len;

	len = 0;
	i = -1;
	while (ins[++i])
	{
		if (ins[i] == 1)
			len += ft_putchar(c);
		else if (ins[i] == 2)
			len += print_width(spec.width, 1, ' ');
	}
	free(ins);
	return (len);
}

int	print_c(int c, t_spec spec)
{
	int	*ins;

	if (!(spec.flag % 2))
		ins = get_instruction(2, 1, 2);
	else
		ins = get_instruction(2, 2, 1);
	return (instruction_c(c, spec, ins));
}
