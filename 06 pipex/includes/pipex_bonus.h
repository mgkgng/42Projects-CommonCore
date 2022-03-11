/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:42:14 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/11 11:48:23 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>

typedef struct s_pipex{
	int		*in;
	int		*out;
	char	**cmd;
	char	***args;
	char	**paths;
	char	**envp;
}	t_pipex;

typedef struct s_cmd{
	char	**cmd;
	char	***args;
	char	*infile;
	char	*outfile;
}	t_cmd;

char	*cmd_define(char *s);
char	*pathname_creator(char *s, char **paths);
int		path_detector(char *s);
char	**possible_path(char **envp);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	here_doc(char *limiter);
char	*get_data(int fd);
int		ft_strcmp(char *s1, char *s2);
t_cmd	all_commands(int argc, char **argv, t_envp path);
void	pipe_loop(t_cmd cmds, t_envp path);
void	ft_free(t_cmd *result);

#endif
