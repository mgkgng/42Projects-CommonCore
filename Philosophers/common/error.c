/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:17:42 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/22 16:47:34 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_m.h"

int	err_check(int argc, char **argv)
{
	int	i;
	int	j;
	int	err;

	err = 0;
	if (argc != 5 && argc != 6)
		err = -1;
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			if (!ft_isdigit(argv[i][j]))
				err = -2;
		if (ft_atoi(argv[i]) <= 0)
			err = -3;
	}
	return (err);
}
