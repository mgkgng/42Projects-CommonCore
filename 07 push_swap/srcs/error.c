/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:11:16 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/24 13:17:42 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

int	check_error(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		if (!digit_check(argv[i]) || !ft_strlen(argv[i]))
			return (1);
		too_big(argv[i]);
		j = 0;
		while (++j < argc)
			if (i != j && !ft_strcmp(argv[i], argv[j]))
				return (1);
	}
	return (0);
}
