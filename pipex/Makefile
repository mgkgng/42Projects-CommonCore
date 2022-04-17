SRCS =	srcs/main.c				\
		srcs/pipex.c			\
		srcs/pipex_utils.c		\

BSRCS =	bonus/main_bonus.c			\
		bonus/pipex_bonus.c			\
		bonus/pipex_utils_bonus.c	\
		bonus/path_bonus.c

ifndef WITH_BONUS
	OBJS = $(SRCS:.c=.o)
else
	OBJS = $(BSRCS:.c=.o)
endif

NAME = pipex

CFLAGS = -Wall -Wextra -Werror

LIB_PATH = ./libft/

%.o :	%.c
		gcc -o $@ -c $< $(CFLAGS) -fsanitize=address

all : $(NAME)

$(NAME) :	$(OBJS)
			make all -C $(LIB_PATH)
			gcc $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a -fsanitize=address

bonus :
			make WITH_BONUS=1 all

clean :
		rm -f $(SRCS:.c=.o) $(BSRCS:.c=.o) 
		make clean -C $(LIB_PATH)

fclean : 	clean
			rm -f $(NAME)
			make fclean -C $(LIB_PATH)

re : fclean all

.PHONY : all bonus clean fclean re
