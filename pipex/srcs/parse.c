/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:44:05 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/03 01:48:29 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_pipex parse(char **argv, char **envp)
{
    t_pipex res;
    
    res.in = argv[1];
	res.out = argv[4];
    res.cmd1 = argv[2];
    res.cmd2 = argv[3];
    res.paths = get_paths(envp);
    res.envp = envp;
    return (res);
}