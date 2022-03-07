/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:15:39 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/07 20:43:59 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int free_pipex(t_pipex pipex)
{
    int i;

    close(pipex.in);
    close(pipex.out);
    free(pipex.cmd1);
    free(pipex.cmd2);
    i = -1;
    while (!pipex.path[++i])
        free(pipex.path[i]);
    free(pipex.path);
    return (0);
}