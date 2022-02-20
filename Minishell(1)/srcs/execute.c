/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:54:12 by min-kang          #+#    #+#             */
/*   Updated: 2022/01/16 15:54:14 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int    execute_loop(t_node *node, char **envp, int fd_in)
{
	int		fd[2];
	pid_t	pid;

	if (node && node->node_type > 1)
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			close(fd[0]);
			if (node->right && node->right->node_type > 1)
				cmd_execute(node->left, fd_in, fd[1], envp);
			else
				cmd_execute(node, fd_in, 1, envp);
			write(fd[1], "", 1);
			exit(127);
		}
		else
		{
			close(fd[1]);
			execute_loop(node->right, envp, fd[0]);
			close(fd[0]);
			waitpid(pid, &res_shell, 0);
			res_shell = WEXITSTATUS(res_shell);
		}
	}
	return (res_shell);
}

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
	if (ft_strlen(txt))
		res[i++] = '\n';
	j = -1;
	while (r[++j])
		res[i + j] = r[j];
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
	free(txt);
	return (fd_tmp);
}

char	*pathname_creator(char *s, char **paths)
{
	char	*cmd;
	int		i;

	if (access(s, F_OK) == 0)
		return (s);
	i = -1;
	while (paths[++i])
	{
		cmd = ft_strjoin(paths[i], "/", 0);
		cmd = ft_strjoin(cmd, s, 1);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		else
			free(cmd);
	}
	ft_putstr_fd("Error: command not found\n", 2);
	return (NULL);
}

char	**possible_path(char **envp)
{
	int		i;
	char	**result;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	result = ft_split(envp[i], ':');
	return (result);
}

char	*path_define(char *cmd, char **envp)
{
	char	*cmd_path;
	char	**paths;

	/*if (!ft_strcmp(cmd, "cd") || !ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, "unset") 
	|| !ft_strcmp(cmd, "exit") || !ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "env")
	|| !ft_strcmp(cmd, "export"))
		return (ft_strjoin("../srcs/builtin/ft_", cmd, 0));*/
	paths = possible_path(envp);
	cmd_path = pathname_creator(cmd, paths);
	return (cmd_path);
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
			redir->output = open(name[i], O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
		else if (type[i] == DOUBLE_CHEVRON_I)
			redir->input = here_doc(name[i]);
		else
			redir->output = open(name[i], O_CREAT | O_WRONLY | O_APPEND);
		if (redir->input == -1 || redir->output == -1)
			ft_putstr_fd("Error : Wrong filename.\n", 2);
	}
}

int	cmd_execute(t_node *node, int fd_in, int fd_out, char **envp)
{
	t_redir	redir;
	char	*cmd_path;

	redir = redir_initialize(fd_in, fd_out);
	if (node->right)
		redir_define(&redir, node->right->redir_name, node->right->redir_type);
	//printf("so? %d\n", redir.input);
	dup2(redir.input, 0);
	dup2(redir.output, 1);
	cmd_path = path_define(node->left->args[0], envp);
	if (!cmd_path)
			exit(127);
	execve(cmd_path, node->left->args, envp);
	exit (127);
}

int	execute(t_node *node, char **envp)
{
	int	success;

	success = execute_loop(node->root, envp, 0);
	//unlink(HEREDOC);
	// free_node(node);
	return (success);
}