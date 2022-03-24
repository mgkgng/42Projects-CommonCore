/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:50:45 by gkgpteam          #+#    #+#             */
/*   Updated: 2022/03/16 15:36:13 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>

# define HEREDOC "here_doc"

extern int	g_res;
int			g_res;

typedef enum e_lex {
	ARG,
	CHEVRON_I,
	CHEVRON_O,
	DOUBLE_CHEVRON_I,
	DOUBLE_CHEVRON_O,
	PIPE,
	OR,
	AND,
	P_OPEN,
	P_CLOSE,
	INPUT,
	LIMITER,
	OUTPUT_T,
	OUTPUT_A,
	WILDCARD
}	t_lex;

/*
<NODE TYPES>
0 : ARGS
1 : REDIR
2 : CMD
3 : PIPE
*/

typedef struct s_node {
	int				node_type;
	char			**args;
	int				*redir_type;
	char			**redir_name;
	struct s_node	*left;
	struct s_node	*right;
	struct s_node	*root;
	struct s_node	*current_cmd;
	struct s_node	*current_pipe;
}	t_node;

typedef struct s_token {
	enum e_lex		token;
	int				begin;
	int				index;
	char			*content;
	struct s_token	*next;
}	t_token;

typedef struct s_redir {
	int	input;
	int	output;
}	t_redir;

/* prototypes */
int			shell(t_app *app, t_token *tokens, int index, char **envp);

/* dep */
void		ft_putstr(char *s);
int			ft_strlen(char *s);
char		*ft_strdup(char *s);
int			ft_strncmp(char *s1, char *s2, int n);
char		*ft_strjoin(char *s1, char *s2, int re);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char *s, char c);
void		ft_putstr_fd(char *s, int fd);
void		ft_putstr(char *s);
int			ft_strcmp(char *s1, char *s2);
char		*ft_substr(char *s, int start, int len);
int			ft_chr_count(char *s, char c);
int			is_alpha(char c);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strfcat(char *s, char c);
char		*ft_itoa(int n);
char		*to_lower(char *s);
void		free2d(void *ptr, void *ptr2);
void		dup2_2d(int stdin, int stdout);
void		close_2d(int std1, int std2);

/* lexer */
t_token		*lexer(char *s, char **envp);
void		token_addback(t_token **tokens, t_token *new);
int			give_token(t_token **tokens, int token, int index);
int			lexer_error(t_token *tokens);
void		*free_tokens(t_token *tokens);
void		put_token_index(t_token **tokens);
void		put_begin(t_token **tokens);
int			rewrite_wildcard(t_token **tokens, char *str);
int			arg_len(char *s, int i, int flag);

/* parser */
void		parse_cmd(t_node **node, char *new_arg);
void		parse_redir(t_node **node, t_token **tokens);
void		parse_pipe(t_node **node);
t_node		*last_node(t_node *node);
void		last_cmd(t_node **node);
int			redir_input(t_token **tokens, char *s, int index);
int			redir_output(t_token **tokens, char *s, int index);
int			is_arg(char c);
char		*put_arg(char *s, int index);
int			get_arg(t_token **tokens, char *s, int index, char **envp);
char		*get_var_arg(char *s);
char		*find_var(char *s, char **envp);
char		*get_var(char *s, int i, char **envp);
int			define_var(t_token **tokens, char *s, int i, char **envp);
int			len_varname(char *s, int i);
int			put_var(char **res, char *s, int i, char **envp);
t_node		*parser(t_token *tokens, int index);
char		**parse_path(char **envp);
char		*define_path(char *cmd, char **paths);

/* execute */
int			parse_execute(t_app *app, t_token *begin, int index);
int			cmd_execute(t_app *app, t_node *node, int *fd);
int			execute_loop(t_app *app, t_node *node, int fd_in);
void		proc_child(t_app *app, t_node *node, int fd_in, int *fd);
int			proc_parent(t_app *app, t_node *node, int *fd, pid_t pid);
char		*path_define(char *cmd, char **envp);
char		*here_doc_join(char *txt, char *r);
int			here_doc(char *limiter);
t_redir		redir_initialize(int fd_in, int fd_out);
int			redir_define(t_redir *redir, char **name, int *type, int pid);
int			builtin_execute(t_node *node, t_app *app, int pid);
int			builtin_check(t_node *node);
void		free_node(t_node *node);
void		free_args(char **args);
void		free_redir(t_node *node);
void		print_error(char *s, int pid);

#endif
