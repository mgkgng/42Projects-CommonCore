/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:44:51 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/23 13:04:04 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_b.h"

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
