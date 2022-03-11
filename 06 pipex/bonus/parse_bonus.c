/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:48:05 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/11 11:51:10 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

t_pipex	parse(int argc, char **argv, char **envp)
{
	t_pipex	res;
	res.in = open(argv[1], O_RDONLY);
	if (res.in == -1)
	{
        ft_putstr_fd("Error 5: input file\n", 2);
		exit(5);
	}
	res.out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (res.out == -1)
    {
        ft_putst_fd("Error 6: output file\n", 2);
        exit(6);
    }

	res.paths = get_paths(envp);
	res.envp = envp;
}