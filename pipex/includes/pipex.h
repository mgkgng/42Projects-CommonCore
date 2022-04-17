/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:43:52 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/17 20:28:56 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_pipex{
	char	*filename[2];
	char	**arg[2];
	char	**paths;
	char	**envp;
}	t_pipex;

t_pipex parse(char **argv, char **envp);
char	*get_cmdpath(char *s, char **paths);
char	**get_paths(char **envp);
int 	terminate(t_pipex pipex);

#endif
