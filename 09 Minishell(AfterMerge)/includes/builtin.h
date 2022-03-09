/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:29:15 by gkgpteam          #+#    #+#             */
/*   Updated: 2022/02/23 16:57:45 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

typedef struct s_app	t_app;

int			ft_cd(char *path);
int			ft_echo(char **args);
int			ft_env(t_app *app);
int			ft_export(t_app *app, char **args);
int			ft_pwd(void);
int			ft_unset(t_app *app, char **args);
int			ft_exit(void);

#endif
