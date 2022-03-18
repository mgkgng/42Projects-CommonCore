SRCS =	./srcs/main.cpp \
		./srcs/PhoneBook.cpp \
		./srcs/Contact.cpp

OBJS =	${SRCS:.cpp=.o}

NAME =	Phonebook

INCLUDE = ./includes/

CFLAGS	= -Wall -Wextra -Werror

CPPFLAG =	-std=c++98

all:	${NAME}

%.o:	%.cpp 
		clang++ ${CLFAGS} ${CPPFLAG} -I${INCLUDE} -c $< -o $@

${NAME}:	${OBJS}
			clang++ ${CFLAGS} ${CPPFLAG} -o ${NAME} ${OBJS}

clean:
		rm -rf ${OBJS}

fclean:	clean
		rm -rf ${NAME}

re:	fclean all