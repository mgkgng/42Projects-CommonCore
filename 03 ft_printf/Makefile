SRCS =	srcs/ft_printf.c \
		srcs/ft_printf_utils.c \
		srcs/print.c \
		srcs/print_utils.c

BSRCS = bonus/ft_printf_bonus.c \
		bonus/ft_printf_utils_bonus.c \
		bonus/get_bonus.c \
		bonus/print_bonus.c \
		bonus/print_utils_bonus.c \
		bonus/print_c_bonus.c \
		bonus/print_d_bonus.c \
		bonus/print_p_bonus.c \
		bonus/print_s_bonus.c \
		bonus/print_u_bonus.c \
		bonus/print_x_bonus.c \
		bonus/width_bonus.c

ifndef WITH_BONUS
	OBJS =	${SRCS:.c=.o}
else
	OBJS =	${BSRCS:.c=.o}
endif

NAME =	libftprintf.a

INCLUDES = ./includes/

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
			gcc ${CFLAGS} -I${INCLUDES} -c $< -o ${<:.c=.o}

clean:
			rm -f ${SRCS:.c=.o} ${BSRCS:.c=.o} 
			make clean -C ${LIB_PATH}

fclean:		clean
			rm -f ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re
