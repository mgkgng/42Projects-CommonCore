/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:52:21 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/20 15:57:25 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_check(t_node *node)
{
	char	*cmd;

	cmd = node->args[0];
	if (!ft_strcmp("cd", to_lower(cmd)))
		return (1);
	else if (!ft_strcmp("echo", to_lower(cmd)))
		return (2);
	else if (!ft_strcmp("env", to_lower(cmd)))
		return (3);
	else if (!ft_strcmp("exit", to_lower(cmd)))
		return (4);
	else if (!ft_strcmp("export", to_lower(cmd)))
		return (5);
	else if (!ft_strcmp("pwd", to_lower(cmd)))
		return (6);
	else if (!ft_strcmp("unset", to_lower(cmd)))
		return (7);
	else
		return (-1);
}

/*
int	builtin_execute(t_node *node,)
{
	char	*cmd;

	cmd = node->args[0];
	if (!ft_strcmp("cd", to_lower(cmd)))
		return (ft_cd(node->args[1]));
	else if (!ft_strcmp("echo", to_lower(cmd)))
		return (ft_echo(&node->args[1]));
	else if (!ft_strcmp("env", to_lower(cmd)))
		return (ft_env(app));
	else if (!ft_strcmp("exit", to_lower(cmd)))
		return (ft_exit(pid, &node->args[1]));
	else if (!ft_strcmp("export", to_lower(cmd)))
		return (ft_export(app, &node->args[1]));
	else if (!ft_strcmp("pwd", to_lower(cmd)))
		return (ft_pwd());
	else if (!ft_strcmp("unset", to_lower(cmd)))
		return (ft_unset(app, &node->args[1]));
	else
		return (-1);
}*/