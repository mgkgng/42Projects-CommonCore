MSRCS =	srcs/main.c				\
		srcs/op_aff1.c			\
		srcs/op_aff2.c			\
		srcs/op_aff3.c			\
		srcs/push_swap.c		\
		srcs/push_swap_a.c		\
		srcs/push_swap_b.c		\
		srcs/push_swap_c.c

CSRCS =	common/push_swap_utils.c	\
		common/push_swap_utils2.c	\
		common/operation1.c		\
		common/operation2.c		\
		common/operation3.c		\
		common/free.c			\
		common/error.c			\
		common/parse.c

BSRCS =	bonus/main.c			\
		bonus/checker.c

NAME =	push_swap
BNAME = checker

MOBJS = $(MSRCS:.c=.o)
COBJS = ${CSRCS:.c=.o}
BOBJS = $(BSRCS:.c=.o)

INCLUDES = ./includes/

CFLAGS = -Wall -Wextra -Werror

LIB_PATH = ./libft/

%.o:	%.c
		gcc -o $@ -c $< $(CFLAGS) -I${INCLUDES}

all : $(NAME)

bonus	:	$(COBJS) $(BOBJS)
			make all -C $(LIB_PATH)
			gcc $(CFLAGS) -I${INCLUDES} -o $(BNAME) $(BOBJS) $(COBJS) libft/libft.a

$(NAME) :	$(COBJS) $(MOBJS)
			make all -C $(LIB_PATH)
			gcc $(CFLAGS) -I${INCLUDES} -o $(NAME) $(MOBJS) $(COBJS) libft/libft.a

clean :
			rm -f $(MOBJS) $(COBJS) $(BOBJS)
			make clean -C $(LIB_PATH)

fclean :	clean
			rm -f $(NAME) $(BNAME)
			make fclean -C $(LIB_PATH)

re :		fclean all

.PHONY : all clean fclean re bonus
