/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:11:16 by min-kang          #+#    #+#             */
/*   Updated: 2022/01/08 17:12:02 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	too_big(char *s)
{
	int	lol;

	lol = ft_atoi(s);
}

void	check_error(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		if (!digit_check(argv[i]) || !ft_strlen(argv[i]))
			exit_error();
		too_big(argv[i]);
		j = 0;
		while (++j < argc)
			if (i != j && !ft_strcmp(argv[i], argv[j]))
				exit_error();
	}
}
