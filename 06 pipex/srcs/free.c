/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:15:39 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/03 01:58:20 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int terminate(t_pipex pipex, int *fd)
{
    int i;
    
    i = -1;
    while (!pipex.paths[++i])
        free(pipex.paths[i]);
    free(pipex.paths);
    close(fd[0]);
    close(fd[1]);
    return (0);
}