/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:50:45 by gkgpteam          #+#    #+#             */
/*   Updated: 2022/01/19 15:28:14 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>

extern int  res_shell;

typedef struct s_app
{
	char	*workdir;
}			t_app;

typedef enum e_token {
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
}  e_token;

/*
<NODE TYPES>
0 : ARGS
1 : REDIR
2 : CMD
3 : PIPE
*/

typedef struct s_node {
   int            node_type;
   char           **args;
   int            *redir_type;
   char           **redir_name;
   char           **heredoc;
   struct s_node  *left;
   struct s_node  *right;
   struct s_node  *root;
   struct s_node  *current_cmd;
   struct s_node  *current_pipe;
} t_node;

typedef struct s_token {
   enum e_token   token;
   int            begin;
   int            index;
   char           *content;
   struct s_token *next;
} t_token;

typedef struct s_redir {
   int   input;
   int   output;
}  t_redir;

/* global variable */

/* prototypes */
int minishell(t_token *tokens, int index, char **envp);

/* dep */
void		ft_putstr(char *s);
int		ft_strlen(char *s);
char		*ft_strdup(char *s);
int		ft_strncmp(char *s1, char *s2, int n);
char		*ft_strjoin(char *s1, char *s2, int re);
void    	ft_putstr_fd(char *s, int fd);
char     **ft_split(char *s, char c);
void     ft_putstr_fd(char *s, int fd);
void     ft_putstr(char *s);
int	   ft_strcmp(char *s1, char *s2);
int	   ft_strchr(char *s, char c);
char	   *ft_substr(char *s, int start, int len);
int	   ft_strchr_set(char *s, char *set);
int      ft_chr_count(char *s, char c);
int      is_alpha(char c);
void	   ft_bzero(void *s, size_t n);
void	   *ft_calloc(size_t count, size_t size);
char	   *ft_strcat(char *s, char c);
char     *ft_itoa(int n);


/* lexer */
t_token	*lexer(char *s, char **envp);
void	token_addback(t_token **tokens, t_token *new);
int	give_token(t_token **tokens, int token, int index);
int	lexer_error(t_token *tokens);
void	*free_tokens(t_token *tokens);
void	put_token_index(t_token **tokens);
void	put_begin(t_token **tokens);

/* parser */
void	parse_cmd(t_node **node, char *new_arg);
void	parse_redir(t_node **node, t_token **tokens);
void	parse_pipe(t_node **node);
t_node	*last_node(t_node *node);
void	last_cmd(t_node **node);



/* redir */
int	redir_input(t_token **tokens, char *s, int index);
int	redir_output(t_token **tokens, char *s, int index);

/* arg */
int   is_arg(char c);
int   arg_len(char *s, int index, int flag);
char  *put_arg(char *s, int index);
int   get_arg(t_token **tokens, char *s, int index, char **envp);

/* var */
char  *get_var_arg(char *s);
char  *find_var(char *s, char **envp);
char  *get_var(char *s, int i, char **envp);
int   define_var(t_token **tokens, char *s, int i, char **envp);
int	len_varname(char *s, int i);
int	put_var(char **res, char *s, int i, char **envp);

/* parse */
t_node	*parser(t_token *tokens, int index);
char	**parse_path(char **envp);
char	*define_path(char *cmd, char **paths);

/* execute */
int	execute(t_node *node, char **envp);
int	cmd_execute(t_node *node, int fd_in, int fd_out, char **envp);

#endif
