SRCS =	srcs/main.c \
		srcs/minishell.c \
		srcs/lexer/lexer.c \
		srcs/lexer/lexer_utils.c \
		srcs/lexer/arg.c \
		srcs/lexer/redir.c \
		srcs/lexer/var.c \
		srcs/lexer/free.c \
		srcs/lexer/error.c \
		srcs/parser/parser.c \
		srcs/parser/parser_utils.c \
		srcs/parser/arg.c \
		srcs/parser/pipe.c \
		srcs/parser/redir.c \
		srcs/execute/execute.c \
		srcs/execute/proc.c \
		srcs/execute/path.c \
		srcs/execute/redir.c \
		srcs/execute/builtin.c \
		srcs/execute/free.c \
		srcs/execute/error.c \
		srcs/utils/minishell_utils1.c \
		srcs/utils/minishell_utils2.c \
		srcs/utils/minishell_utils3.c \
		srcs/utils/minishell_utils4.c

INCLUDE = ./includes/

OBJS  = ${SRCS:.c=.o}

NAME  = minishell

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

%.o:	%.c
		gcc ${CFLAGS} -I${INCLUDE} -o $@ -c $< -fsanitize=address

${NAME}:	${OBJS}
			gcc ${CFLAGS} -lreadline -o ${NAME} ${OBJS} -fsanitize=address

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re
