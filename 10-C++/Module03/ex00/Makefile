SRCS =	./main.cpp \
		./ClapTrap.cpp

OBJS =	${SRCS:.cpp=.o}

NAME =	ClapTrap	

CFLAGS	= -Wall -Wextra -Werror

CPPFLAG =	-std=c++98

all:	${NAME}

%.o:	%.cpp 
		clang++ ${CFLAGS} ${CPPFLAG} -c $< -o $@

${NAME}:	${OBJS}
			clang++ ${CFLAGS} ${CPPFLAG} -o ${NAME} ${OBJS}

clean:
		rm -rf ${OBJS}

fclean:	clean
		rm -rf ${NAME}

re:	fclean all