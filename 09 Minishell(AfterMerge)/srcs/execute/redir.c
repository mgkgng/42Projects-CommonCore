/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:23:47 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/21 16:26:02 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*here_doc_join(char *txt, char *r)
{
	int		i;
	int		j;
	char	*res;

	if (!txt)
		txt = ft_strdup("");
	if (!r)
		return (txt);
	res = ft_calloc(ft_strlen(txt) + ft_strlen(r) + 2, sizeof(char));
	i = -1;
	while (txt[++i])
		res[i] = txt[i];
	j = -1;
	while (r[++j])
		res[i + j] = r[j];
	res[i + j++] = '\n';
	res[i + j] = '\0';
	free(txt);
	free(r);
	return (res);
}

int	here_doc(char *limiter)
{
	char	*r;
	char	*txt;
	int		fd_tmp;

	txt = NULL;
	while (1)
	{
		r = readline("");
		if (!ft_strcmp(limiter, r))
			break ;
		txt = here_doc_join(txt, r);
	}
	fd_tmp = open(HEREDOC, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	write(fd_tmp, txt, ft_strlen(txt));
	close(fd_tmp);
	fd_tmp = open(HEREDOC, O_RDONLY);
	free(txt);
	return (fd_tmp);
}

t_redir	redir_initialize(int fd_in, int fd_out)
{
	t_redir	res;

	res.input = 0;
	res.output = 1;
	if (fd_in)
		res.input = fd_in;
	if (fd_out)
		res.output = fd_out;
	return (res);
}

void	redir_define(t_redir *redir, char **name, int *type)
{
	int		i;

	i = -1;
	while (name[++i])
	{
		if (type[i] == CHEVRON_I)
			redir->input = open(name[i], O_RDONLY);
		else if (type[i] == CHEVRON_O)
			redir->output = open(name[i], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else if (type[i] == DOUBLE_CHEVRON_I)
			redir->input = here_doc(name[i]);
		else
			redir->output = open(name[i], O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (redir->input == -1 || redir->output == -1)
		{
			ft_putstr_fd("Error : Wrong filename.\n", 2);
			exit(1);
		}
	}
}
