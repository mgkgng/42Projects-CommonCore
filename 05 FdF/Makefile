CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB_PATH = ./libft/
MLX = -lmlx -framework OpenGL -framework AppKit
NAME = fdf
SRC =	srcs/fdf.c		\
		srcs/draw.c		\
		srcs/formulization.c	\
		srcs/color.c	\
		srcs/action.c	\
		srcs/draw_cavalier.c \
		srcs/draw2.c \
		srcs/draw3.c	\
		srcs/lol.c

BONUS = bonus/draw_cavalier.c	
OBJ = $(SRC:.c=.o)
RM = rm -f
%.o :	%.c
		$(CC) -o $@ -c $< $(CFLAGS)
all : $(NAME)
$(NAME)     :   $(OBJ)
				make all -C $(LIB_PATH)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) libft/libft.a
clean :
		$(RM) $(OBJ)
		make clean -C $(LIB_PATH)
fclean : clean
		$(RM) $(NAME)
		make fclean -C $(LIB_PATH)
re : fclean all
.PHONY : all clean fclean re
