/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgk <mgk@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:42:14 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/11 21:12:27 by mgk              ###   ########.fr       */
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
	int		in;
	int		out;
	char	**cmds;
	char	**paths;
	char	**envp;
}	t_pipex;

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	here_doc(char *limiter);
char	*get_data(int fd);
int		ft_strcmp(char *s1, char *s2);
char	**all_commands(int argc, char **argv);
void	execute_loop(t_pipex pipex);
t_pipex	parse(int argc, char **argv, char **envp);


#endif
