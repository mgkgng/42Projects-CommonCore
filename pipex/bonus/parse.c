/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:48:05 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/17 20:03:33 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

char	***get_args(int argc, char **argv)
{
	char	**res;
	int		i;
	int		j;
	int		size;

	size = argc - 2;
	i = 1;
	if (!ft_strcmp("here_doc", argv[1]))
	{
		size--;
		i++;
	}
	res = ft_calloc(size + 1, sizeof(char **));
	j = 0;
	while (i < argc - 1)
		res[j++] = ft_split(argv[i++], ' ');
	res[j] = NULL;
	return (res);
}

t_pipex	parse(int argc, char **argv, char **envp)
{
	t_pipex	res;

	if (!ft_strcmp(argv[1], "here_doc"))
		res.in = heredoc(argv[2]);
	else
		res.in = open(argv[1], O_RDONLY);
	res.out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	res.args = get_args(argc, argv);
	res.cmdpaths = get_cmdpaths(res.args, envp);
	res.envp = envp;
}