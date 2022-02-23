/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:16:01 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/22 16:47:24 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_m.h"

int	main(int argc, char **argv)
{
	t_arg	args;

	if (err_check(argc, argv))
	{
		ft_putstr_fd("Error.\n", 2);
		return (-1);
	}
	args = parser(argc, argv);
	philosophers(args);
	return (0);
}
