SRCS =	ft_atoi.c \
		ft_isdigit.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strlen.c

NAME = libft.a

OBJS = ${SRCS:.c=.o}

INCLUDES = ../includes/

CFLAG = -Wextra -Wall -Werror

all:		${NAME}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			
.c.o:
			gcc ${CFLAG} -I${INCLUDES} -c $< -o ${<:.c=.o}
			
clean:	
			rm -f ${OBJS} ${BOJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:	all clean fclean re
