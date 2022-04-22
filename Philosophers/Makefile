SRCS_M =	srcs/main.c \
			srcs/philo.c \
			srcs/free.c \
			srcs/gameover.c \
			srcs/eat_sleep_think.c

SRCS_C = 	common/utils1.c \
			common/utils2.c \
			common/parser.c \
			common/error.c \
			common/time.c

SRCS_B =	bonus/main.c \
			bonus/philo.c \
			bonus/free.c \
			bonus/sem.c \
			bonus/die.c \
			bonus/gameover.c \
			bonus/eat_sleep_think.c

ifndef WITH_BONUS
	OBJS = ${SRCS_M:.c=.o}
else
	OBJS = ${SRCS_B:.c=.o}
endif

OBJS_C = ${SRCS_C:.c=.o}

NAME = philo

CFLAG = -Wall -Wextra -Werror

all: ${NAME}

bonus:
		make WITH_BONUS=1 all

.c.o:
			gcc ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${OBJS_C}
			gcc $(CFLAGS) -o $(NAME) ${OBJS} ${OBJS_C}

clean:
		rm -rf ${SRCS_M:.c=.o} ${SRCS_B:.c=.o} ${OBJS_C}

fclean: clean
		rm -rf ${NAME}

re: fclean all

.PHONY:	bonus all clean fclean re