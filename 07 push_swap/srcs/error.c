/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:11:16 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/24 01:49:30 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	too_big(char *s)
{
	int	lol;

	lol = ft_atoi(s);
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
