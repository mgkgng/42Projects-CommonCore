/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:43:52 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/07 13:53:28 by min-kang         ###   ########.fr       */
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
	int		input;
	int		output;
	char	*cmd1;
	char	*cmd2;
	char	**path;
	char	**envp;
}	t_pipex;

char	*cmd_define(char *s);
char	*pathname_creator(char *s, char **paths);
char	**get_path(char **envp);
void	child_pipex(char *cmd, char *input, t_envp path, int *fd);
void	parent_pipex(char *cmd, char *output, t_envp path, int *fd);
void	ft_putstr(char *s);
int		ft_pipex(char **argv, char **envp);
int		error(int code);
t_pipex	parse(char **argv, char **envp);

#endif
