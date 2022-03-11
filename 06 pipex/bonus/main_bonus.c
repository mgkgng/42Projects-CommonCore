/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:36:37 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/11 11:46:47 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_envp	path;
	t_cmd	cmds;

	if (argc < 5)
		return (error(1));
	return (ft_pipex(parse(argv, envp)));

	path.paths = possible_path(envp);
	path.envp = envp;
	if (!ft_strcmp(argv[1], "here_doc"))
		here_doc(argv[2]);
	cmds = all_commands(argc, argv, path);
	cmds.infile = argv[1];
	cmds.outfile = argv[argc - 1];
	pipe_loop(cmds, path);
	if (!ft_strcmp(argv[1], "here_doc"))
		unlink("here_doc");
	free(cmds.cmd);
	free(cmds.args);
	return (0);
}
