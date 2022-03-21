/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:49:04 by gkgpteam          #+#    #+#             */
/*   Updated: 2022/03/16 21:47:48 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <termios.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

static void	accept(t_app *app, char *str_cmd)
{
	char			**env;
	t_token			*tokens;
	int				i;

	if (str_cmd && *str_cmd)
		add_history(str_cmd);
	env = list_env_to_2d(app);
	app->envp = env;
	tokens = lexer(str_cmd, env);
	if (tokens)
	{
		g_res = shell(app, tokens, 0, env);
		free_tokens(tokens);
	}
	else
		g_res = 258;
	i = -1;
	while (env[++i])
		free(env[i]);
	free(env);
}

static int	ft_readline(t_app *app)
{
	char			*str;
	struct termios	minshell_mode;
	struct termios	back_mode;

	tcgetattr(STDIN_FILENO, &back_mode);
	back_mode.c_lflag |= ECHOCTL;
	minshell_mode = back_mode;
	minshell_mode.c_lflag &= ~ECHOCTL;
	while (app->stay_alive)
	{
		tcsetattr(STDIN_FILENO, TCSANOW, &minshell_mode);
		str = readline("minshell-1.0$ ");
		if (!str)
		{
			ft_putstr("\033[1A");
			ft_putstr(rl_prompt);
			ft_putstr("exit\n");
			return (1);
		}
		tcsetattr(STDIN_FILENO, TCSANOW, &back_mode);
		accept(app, str);
		if (str)
			free(str);
	}
	return (0);
}

int	minishell(int argc, char const *argv[], char *const envp[])
{
	t_app			app;

	init_app(&app);
	init_env(&app, envp);
	(void) argv;
	init_signal();
	if (argc == 1)
		accept(&app, (char *) argv[0]);
	ft_readline(&app);
	free_app(&app);
	return (0);
}
