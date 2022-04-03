# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 14:24:46 by gphilipp          #+#    #+#              #
#    Updated: 2022/03/31 19:58:28 by gphilipp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# <!-- pre='srcs/' path='./' match[regex]='.*(?<!bonus)\.c' exclude='main.c' pos='1' template='		{0} \' -->
SRC	  = main.c \
		dep/ft_get_content.c \
		dep/ft_strlen.c \
		dep/ft_atoi.c \
		dep/ft_itoa.c \
		event/key.c \
		event/window.c \
		list.c \


# <!-- pre='srcs/' path='./' match='*_bonus.c' exclude='main_bonus.c' pos='1' template='		{0} \' -->
SRC_BONUS = main_bonus.c \


ifdef BONUS
	SRC += $(SRC_BONUS)
	_tmpsrc := $(SRC)
	SRC = $(filter-out main.c, $(_tmpsrc))
endif

# <!-- pre='includes/' path='./' match='*.h' exclude='minirt.h' pos='1' template='		{0} \' -->
HDEP  = minirt.h \
		point.h \
		color.h \
		list.h \
		libx.h \
		dep.h \


HDEPS = $(addprefix $(HEAD), $(HDEP))

SRCS  = $(addprefix $(PRE), $(SRC))

OBJS  = $(SRCS:.c=.o)

PRE	  = ./srcs/

HEAD  = ./includes/

NAME  = minirt

ifdef BONUS
	NAME = minirt_bonus
endif

CC    = gcc

CFLAGS = -Wall -Wextra -Werror

COMPILEFLAGS = -L$(MINILIBX) -lmlx -framework OpenGL -framework AppKit \
			   -L$(LIBLIST) -llist

all: libs $(NAME)

%.o: %.c $(HDEPS)
	$(CC) $(CFLAGS) -I $(HEAD) -c $< -o $@

MINILIBX = vendor/minilibx/

LIBLIST = vendor/liblist/

libs: $(MINILIBX)libmlx.a $(LIBLIST)liblist.a

mlx: $(MINILIBX)libmlx.a

list: $(LIBLIST)liblist.a

$(MINILIBX)libmlx.a:
	git submodule update --init $(MINILIBX)
	make -C $(MINILIBX)

$(LIBLIST)liblist.a:
	git submodule update --init $(LIBLIST)
	make -C $(LIBLIST)

libs_clean:
	make -C $(MINILIBX) clean
	make -C $(LIBLIST) clean

libs_fclean: libs_clean
	make -C $(MINILIBX) fclean
	make -C $(LIBLIST) fclean

bonus: $(NAME)
	@make BONUS=1

$(NAME): $(OBJS) $(HDEPS)
	$(CC) $(CFLAGS) -o $(NAME) $(COMPILEFLAGS) $(OBJS)

$(NAME)_debug: $(SRCS) $(HDEPS)
	$(CC) $(CFLAGS) -g -o $(NAME)_debug -I $(HEAD) $(COMPILEFLAGS) $(SRCS)

$(NAME)_sanitize: $(SRCS) $(HDEPS)
	$(CC) $(CFLAGS) -fsanitize=address -g -o $(NAME)_sanitize -I $(HEAD) $(COMPILEFLAGS) $(SRCS)

debug: $(NAME)_debug

sanitize: $(NAME)_sanitize

dclean: fclean
	rm -f *.out
	rm -rf *.dSYM
	rm -f $(NAME)_debug
	rm -f $(NAME)_sanitize
	find . -iname "*.o" -exec rm -i {} ";"

clean:
ifndef BONUS
		make -s BONUS=1 clean;
endif
	rm -f $(OBJS)

fclean: libs_fclean clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean dclean fclean bonus debug sanitize libs mlx list libs_clean libs_fclean re
