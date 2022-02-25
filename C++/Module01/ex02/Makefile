SRCS =	./main.cpp

OBJS =	${SRCS:.cpp=.o}

NAME =	HiBrain

CFLAGS	= -Wall -Wextra -Werror

CPPFLAG =	-std=c++98

all:	${NAME}

%.o:	%.cpp 
		gcc -c $< -o $@

${NAME}:	${OBJS}
			g++ ${CFLAGS} ${CPPFLAG} -o ${NAME} ${OBJS}

clean:
		rm -rf ${OBJS}

fclean:	clean
		rm -rf ${NAME}

re:	fclean all