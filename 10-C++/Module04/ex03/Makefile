SRCS =	srcs/main.cpp \
		srcs/AMateria.cpp \
		srcs/Ice.cpp \
		srcs/Cure.cpp \
		srcs/Character.cpp \
		srcs/MateriaSource.cpp

OBJS =	${SRCS:.cpp=.o}

NAME =	Character

INCLUDE = ./includes/

CFLAGS	= -Wall -Wextra -Werror

CPPFLAG =	-std=c++98

all:	${NAME}

%.o:	%.cpp 
		clang++ ${CFLAGS} ${CPPFLAG} -I${INCLUDE} -c $< -o $@

${NAME}:	${OBJS}
			clang++ ${CFLAGS} ${CPPFLAG} -o ${NAME} ${OBJS}

clean:
		rm -rf ${OBJS}

fclean:	clean
		rm -rf ${NAME}

re:	fclean all