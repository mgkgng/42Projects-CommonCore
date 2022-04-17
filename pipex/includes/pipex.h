/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:43:52 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/17 19:40:27 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>

typedef struct s_pipex{
	char	*filename[2];
	char	**arg[2];
	char	**paths;
	char	**envp;
}	t_pipex;

/* path */
char	*get_cmdpath(char *s, char **paths);
char	**get_paths(char **envp);

void	child_pipex(t_pipex pipex, int *fd);
void	parent_pipex(t_pipex pipex, int *fd);
void	ft_putstr(char *s);
int		ft_pipex(t_pipex pipex);
int		error(int code, char *s);
t_pipex	parse(char **argv, char **envp);
int free_pipex(t_pipex pipex);

#endif
