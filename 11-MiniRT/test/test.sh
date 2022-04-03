#!/bin/sh

HEAD="./includes/"

make
make bonus
if [[ $? == 0 ]]; then
	SRCS=$(find ./srcs/ -iname "*.c" ! -name "main.c")
	echo "========= MINIRT ========="
	sh ./test/allowed_function.sh
	#gcc -g -o test.out ./test/test.c $SRCS -fno-builtin -I "$HEAD" && ./test.out && rm ./test.out
	echo "=========================="
	norminette ./srcs/*.c ./srcs/**/*.c ./includes/*.h | grep -v ": OK!"
fi
