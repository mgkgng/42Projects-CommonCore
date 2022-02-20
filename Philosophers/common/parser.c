/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:19:23 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/11 16:19:38 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_c.h"

t_arg	parser(int argc, char **argv)
{
	t_arg	result;

	result.p_nb = ft_atoi(argv[1]);
	result.t_die = ft_atoi(argv[2]);
	result.t_eat = ft_atoi(argv[3]);
	result.t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		result.e_nb = ft_atoi(argv[5]);
	else
		result.e_nb = 0;
	return (result);
}
