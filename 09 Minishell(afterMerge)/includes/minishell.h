/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:50:45 by gkgpteam          #+#    #+#             */
/*   Updated: 2022/03/16 18:10:39 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// Reproduction des fonctions bashs (echo, cd, pwd…)
# include "builtin.h"
# include "shell.h"
# include "list.h"

typedef struct s_app
{
	t_list		*env;
	int			stay_alive;
	char		**envp;
}			t_app;

typedef struct s_keyval
{
	char		*key;
	char		*val;
	int			not_d;
}			t_keyval;

/* prototypes */
int			minishell(int argc, char const *argv[], char *const envp[]);

/* app.c */
void		init_app(t_app *app);
void		free_app(t_app *app);

/* builtin/….c utils*/
char		*ft_getcwd(void);

/* env.c */
void		init_env(t_app *app, char *const envp[]);
char		*ft_getenv(t_app *app, char *key);
int			ft_setenv(t_app *app, char *key, char *val, int not_d);
int			ft_unsetenv(t_app *app, char *key);
char		**list_env_to_2d(t_app *app);

/* list2.c */
void		list_free_keyval(void *data);

/* dep */
void		ft_putstr(char *s);
char		*ft_strcat(char *dest, char *src);
char		*ft_strchr(const char *s, int c);

/* signal */
void		init_signal(void);

/* wildcard */
char		**wildcard(char *dirname);

#endif
