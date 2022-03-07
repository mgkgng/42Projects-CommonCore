/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:44:05 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/07 13:53:12 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_pipex parse(char **argv, char **envp)
{
    t_pipex res;
    
    res.input = ft_strdup(argv[1]);
    res.output = ft_strdup(argv[4]);
    res.cmd1 = ft_strdup(argv[2]);
    res.cmd2 = ft_strdup(argv[3]);
    res.path = get_path(envp);
    res.envp = envp;
    return (res);
}