/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:17:56 by gkgpteam          #+#    #+#             */
/*   Updated: 2022/03/16 17:27:58 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <signal.h>
#include <unistd.h>	
#include <readline/readline.h>
#include <readline/history.h>

static void	ft_signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr("\n");
		if (rl_done)
			return ;
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_res = 128 + SIGINT;
	}
	else if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
		g_res = 128 + SIGQUIT;
	}
}

/*
** Utilisation de termios pour cacher ^C et ^D
** https://stackoverflow.com/a/42563972
*/

void	init_signal(void)
{
	signal(SIGINT, ft_signal_handler);
	signal(SIGQUIT, ft_signal_handler);
}
