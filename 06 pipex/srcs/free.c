/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgk <mgk@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:15:39 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/12 14:57:53 by mgk              ###   ########.fr       */
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
    while (!pipex.paths[++i])
        free(pipex.paths[i]);
    free(pipex.paths);
    return (0);
}