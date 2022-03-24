/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:11:16 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/24 21:45:24 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

int	there_is_digit(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (ft_isdigit(s[i]))
			return (1);
	return (0);
}

int	digit_check(char *s)
{
	int	i;

	if (!there_is_digit(s))
		return (0);
	i = -1;
	while (s[++i])
		if (!ft_isdigit(s[i]) && s[i] != '-' && s[i] != '+')
			return (0);
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

// faire deux types de check error -> argc == 2, argc > 2 / en utilisant un flag