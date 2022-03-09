/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:17:56 by gkgpteam          #+#    #+#             */
/*   Updated: 2022/02/22 17:11:27 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <termios.h>
#include <unistd.h>	
#include <readline/readline.h>
#include <readline/history.h>

static void	ft_signal_handler(int sig)
{
	if (sig == 2)
	{
		rl_replace_line("", 0);
		rl_done = 1;
	}
	(void) sig;
}

/*
** HACK: https://stackoverflow.com/a/53167525
** Pour que rl_done soit pris on compte, on a besoin de faire:
** rl_event_hook = ft_rl_event;
** Periodically refresh readline instead to wait for a terminal input
*/
static int	ft_rl_event(void)
{
	return (0);
}

/*
** Utilisation de termios pour cacher ^C et ^D
** https://stackoverflow.com/a/42563972
*/

void	init_signal(void)
{
	struct termios		attributes;

	tcgetattr(STDIN_FILENO, &attributes);
	attributes.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &attributes);
	rl_event_hook = ft_rl_event;
	signal(SIGINT, ft_signal_handler);
}
