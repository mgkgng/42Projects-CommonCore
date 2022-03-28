SRCS =	srcs/main.cpp \
		srcs/Animal.cpp \
		srcs/Dog.cpp \
		srcs/Cat.cpp \
		srcs/Brain.cpp

OBJS =	${SRCS:.cpp=.o}

NAME =	Brain

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