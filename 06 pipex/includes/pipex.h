/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:43:52 by min-kang          #+#    #+#             */
/*   Updated: 2021/12/26 19:44:18 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>

typedef struct s_envp{
	char	**envp;
	char	**paths;
}	t_envp;

char	*cmd_define(char *s);
char	*pathname_creator(char *s, char **paths);
int		path_detector(char *s);
char	**possible_path(char **envp);
void	child_pipex(char *cmd, char *input, t_envp path, int *fd);
void	parent_pipex(char *cmd, char *output, t_envp path, int *fd);
void	ft_putstr(char *s);
void	ft_pipex(char **argv, t_envp path);

#endif
