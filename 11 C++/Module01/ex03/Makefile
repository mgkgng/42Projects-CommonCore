SRCS =	./main.cpp \
		./Weapon.cpp \
		./HumanA.cpp \
		./HumanB.cpp

OBJS =	${SRCS:.cpp=.o}

NAME =	Attack

CFLAGS	= -Wall -Wextra -Werror

CPPFLAG =	-std=c++98

all:	${NAME}

%.o:	%.cpp 
		clang++ ${CFLAGS} ${CPPFLAG}  -c $< -o $@

${NAME}:	${OBJS}
			clang++ ${CFLAGS} ${CPPFLAG} -o ${NAME} ${OBJS}

clean:
		rm -rf ${OBJS}

fclean:	clean
		rm -rf ${NAME}

re:	fclean all