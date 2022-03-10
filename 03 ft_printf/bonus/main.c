#include "ft_printf_bonus.h"
#include <stdio.h>
#include <stdlib.h>

int	main() {
	int test = 1;
	printf("personal test -----------------------\n");
	printf("real printf =========================\n");
	printf("print result: \n");
	printf("value : %d\n", printf("%010.6d\n", 42000));
	printf("print result: \n");
	printf("value : %d\n", printf("%010.4d\n", 42000));
	printf("print result: \n");
	printf("value : %d\n", printf("%010.15d\n", 42000));
	printf("print result: \n");
	printf("value : %d\n", printf("%03.3d\n", 42000));
	printf("print result: \n");
	printf("value : %d\n", printf("%06.2d\n", 42000));
	printf("print result: \n");
	printf("value : %d\n", printf("%010d\n", 42000));
	printf("print result: \n");
	printf("value : %d\n", printf("%010.d\n", 42000));



}