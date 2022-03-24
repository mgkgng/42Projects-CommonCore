MSRCS =	srcs/main.c				\
		srcs/op_aff1.c			\
		srcs/op_aff2.c			\
		srcs/op_aff3.c			\
		srcs/push_swap.c		\
		srcs/push_swap_a.c		\
		srcs/push_swap_b.c		\
		srcs/push_swap_c.c

SRCS =	srcs/push_swap_utils.c	\
		srcs/push_swap_utils2.c	\
		srcs/operation1.c		\
		srcs/operation2.c		\
		srcs/operation3.c		\
		srcs/free.c				\
		srcs/error.c			\
		srcs/parsing.c

BSRCS =	bonus/main.c			\
		bonus/checker.c

NAME =	push_swap
BNAME = checker

MOBJS = $(MSRCS:.c=.o)
OBJS = ${SRCS:.c=.o}
BOBJS = $(BSRCS:.c=.o)

INCLUDES = ./includes/

CFLAGS = -Wall -Wextra -Werror

LIB_PATH = ./libft/

%.o:	%.c
		gcc -o $@ -c $< $(CFLAGS) -I${INCLUDES}

all : $(NAME)

bonus	:	$(OBJS) $(BOBJS)
			make all -C $(LIB_PATH)
			gcc $(CFLAGS) -I${INCLUDES} -o $(BNAME) $(BOBJS) $(OBJS) libft/libft.a

$(NAME) :	$(OBJS) $(MOBJS)
			make all -C $(LIB_PATH)
			gcc $(CFLAGS) -I${INCLUDES} -o $(NAME) $(MOBJS) $(OBJS) libft/libft.a

clean :
			rm -f $(MOBJS) $(OBJS) $(BOBJS)
			make clean -C $(LIB_PATH)

fclean :	clean
			rm -f $(NAME) $(BNAME)
			make fclean -C $(LIB_PATH)

re :		fclean all

.PHONY : all clean fclean re bonus
