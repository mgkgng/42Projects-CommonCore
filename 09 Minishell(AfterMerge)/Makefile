# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 14:24:46 by gkgpteam          #+#    #+#              #
#    Updated: 2022/02/23 16:24:55 by gphilipp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# <!-- pre='srcs/' path='./' match='*.c' exclude='main.c' pos='1' template='		{0} \' -->
SRC	  = main.c \
		lexer/lexer.c \
		lexer/redir.c \
		lexer/free.c \
		lexer/var.c \
		lexer/arg.c \
		lexer/lexer_utils.c \
		lexer/wildcard.c \
		shell/shell.c \
		shell/env.c \
		shell/signal.c \
		shell/app.c \
		shell/wildcard.c \
		shell/minishell.c \
		utils/minishell_utils4.c \
		utils/list.c \
		utils/minishell_utils3.c \
		utils/minishell_utils2.c \
		utils/list2.c \
		utils/minishell_utils1.c \
		parser/pipe.c \
		parser/redir.c \
		parser/parser_utils.c \
		parser/arg.c \
		parser/parser.c \
		execute/execute.c \
		execute/redir.c \
		execute/free.c \
		execute/path.c \
		execute/builtin.c \
		builtin/ft_echo.c \
		builtin/ft_cd.c \
		builtin/ft_unset.c \
		builtin/ft_env.c \
		builtin/ft_pwd.c \
		builtin/ft_exit.c \
		builtin/ft_export.c \


# <!-- pre='includes/' path='./' match='*.h' exclude='minishell.h' pos='1' template='		{0} \' -->
HDEP  = minishell.h \
		builtin.h \
		list.h \
		shell.h \


HDEPS = $(addprefix $(HEAD), $(HDEP))

SRCS  = $(addprefix $(PRE), $(SRC))

OBJS  = $(SRCS:.c=.o)

PRE	  = ./srcs/

HEAD  = ./includes/

NAME  = minishell

CC    = gcc

CFLAGS = -Wall -Wextra -Werror

READLINE_PATH = vendor/readline/

COMPILEFLAGS = -L$(LIBLIST) -llist -L$(READLINE_PATH)/lib -lreadline

all: libs $(NAME)

%.o: %.c $(HDEPS)
	$(CC) $(CFLAGS) -I$(HEAD) -I$(READLINE_PATH)/include -c $< -o $@

LIBLIST = vendor/liblist/

libs: readline $(LIBLIST)liblist.a

list: $(LIBLIST)liblist.a

readline: $(READLINE_PATH)

$(READLINE_PATH):
	sh ./install_readline.sh

$(LIBLIST)liblist.a:
	make -C $(LIBLIST)

libs_clean:
	make -C $(LIBLIST) clean

libs_fclean: libs_clean
	make -C $(LIBLIST) fclean

$(NAME): $(OBJS) $(HDEPS)
	$(CC) $(CFLAGS) -o $(NAME) $(COMPILEFLAGS) $(OBJS)

# Usage: make debug && lldb minishell_debug -o run
$(NAME)_debug: $(SRCS) $(HDEPS)
	$(CC) $(CFLAGS) -g -o $(NAME)_debug -I$(HEAD) -I$(READLINE_PATH)/include $(COMPILEFLAGS) $(SRCS)

$(NAME)_sanitize: $(SRCS) $(HDEPS)
	$(CC) $(CFLAGS) -fsanitize=address -g -o $(NAME)_sanitize -I$(HEAD) -I$(READLINE_PATH)/include $(COMPILEFLAGS) $(SRCS)

# Usage: make leaks && ./minishell_leaks
MAIN_PATH=srcs/main.c
$(NAME)_leaks: $(OBJS) $(HDEPS)
	$(eval main_proto=$(shell grep 'int\tmain' $(MAIN_PATH)))
	$(eval leaks_proto=$(shell echo '$(main_proto)' | sed 's/main/leaks_tester/'))
	$(eval call_main=$(shell echo '$(main_proto)' | sed -E "s/(int| |\*|char|const|void|\[|\])//g"))
	@echo '#include "stdlib.h"\n\n\
	$(main_proto);\n\n\
	$(leaks_proto) {\n\
		\tint exitcode = $(call_main);\n\
		\tsystem("leaks $(NAME)_leaks");\n\
		\treturn (exitcode);\n\
	}' > .tmp_leaks.c
	$(CC) $(CFLAGS) -o $(NAME)_leaks $(COMPILEFLAGS) .tmp_leaks.c $(OBJS) -e_leaks_tester
	@rm .tmp_leaks.c

debug: $(NAME)_debug

sanitize: $(NAME)_sanitize

leaks: $(NAME)_leaks

dclean: fclean
	rm -f *.out
	rm -rf *.dSYM
	rm -f $(NAME)_debug
	rm -f $(NAME)_sanitize
	rm -f $(NAME)_leaks
	find . -iname "*.o" -exec rm -i {} ";"

clean:
ifndef BONUS
		make -s BONUS=1 clean;
endif
	rm -f $(OBJS)

fclean: libs_fclean clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean dclean fclean debug sanitize leaks libs readline list libs_clean libs_fclean re
