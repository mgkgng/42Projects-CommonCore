/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgk <mgk@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:48:05 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/11 21:12:30 by mgk              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

char	**get_cmds(int argc, char **argv)
{
	int		i;
	int		j;
	char	**res;
	int		size;

	size = argc - 2;
	i = 1;
	if (!ft_strcmp("here_doc", argv[1]))
	{
		size--;
		i++;
	}
	res = ft_calloc(size + 1, sizeof(char *));
	j = 0;
	while (i < argc - 1)
		res[j++] = ft_strdup(argv[i++]);
	res[j] = NULL;
	return (res);
}

t_pipex	parse(int argc, char **argv, char **envp)
{
	t_pipex	res;
	if (!ft_strcmp(argv[1], "here_doc"))
		here_doc(argv[2]);
	else
	{
		res.in = open(argv[1], O_RDONLY);
		if (res.in == -1)
		{
    	    ft_putstr_fd("Error 5: input file\n", 2);
			exit(5);
		}
		res.out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (res.out == -1)
		{
			ft_putst_fd("Error 6: output file\n", 2);
        	exit(6);
		}
	}
	res.cmds = get_cmds(argc, argv);
	res.paths = get_paths(envp);
	res.envp = envp;
}