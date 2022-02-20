SRCS =	srcs/main.c \
		srcs/execute.c \
		srcs/minishell.c \
		srcs/lexer/lexer.c \
		srcs/lexer/lexer_utils.c \
		srcs/lexer/arg.c \
		srcs/lexer/redir.c \
		srcs/lexer/var.c \
		srcs/parser/parser.c \
		srcs/parser/parser_utils.c \
		srcs/parser/arg.c \
		srcs/parser/pipe.c \
		srcs/parser/redir.c \
		srcs/utils/minishell_utils1.c \
		srcs/utils/minishell_utils2.c \
		srcs/utils/minishell_utils3.c \
		srcs/utils/minishell_utils4.c

OBJS  = $(SRCS:.c=.o)

NAME  = minishell

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o:	%.c
		gcc -o $@ -c $< $(CFLAGS) -fsanitize=address

$(NAME):	$(OBJS)
			gcc $(CFLAGS) -lreadline -o $(NAME) $(OBJS) -fsanitize=address

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean dclean fclean debug sanitize leaks libs readline list libs_clean libs_fclean re
