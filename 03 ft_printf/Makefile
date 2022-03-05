SRCS =	srcs/ft_printf.c \
		srcs/ft_printf_utils.c \
		srcs/verify_machine.c \

BSRCS = bonus/ft_printf_bonus.c \
		bonus/utils_bonus.c \
		bonus/get.c \
		bonus/print.c \
		bonus/print_d.c \
		bonus/print_p.c \
		bonus/print_s.c \
		bonus/print_u.c \
		bonus/print_x.c \
		bonus/width.c

ifndef WITH_BONUS
	OBJS =	${SRCS:.c=.o}
else
	OBJS =	${BSRCS:.c=.o}
endif

NAME =	libftprintf.a

LIB_PATH = ./libft/

CFLAGS =	-Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${OBJS}
			make all -C ${LIB_PATH}
			cp libft/libft.a ${NAME}
			ar rc ${NAME} ${OBJS}

bonus :		
			make WITH_BONUS=1 all

.c.o:
			gcc ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
			rm -f ${SRCS:.c=.o} ${BSRCS:.c=.o} 
			make clean -C ${LIB_PATH}

fclean:		clean
			rm -f ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re
