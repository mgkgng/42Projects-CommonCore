/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:36:37 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/20 21:49:03 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
	{
		ft_putendl_fd("Wrong number of arguments.", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (ft_pipex(parse(argc, argv, envp)));
}
