/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:32:59 by min-kang          #+#    #+#             */
/*   Updated: 2021/12/24 16:35:22 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_envp	path;

	if (argc != 5)
	{
		perror("wrong number of arguments");
		exit(0);
	}
	path.paths = possible_path(envp);
	path.envp = envp;
	ft_pipex(argv, path);
	return (0);
}
