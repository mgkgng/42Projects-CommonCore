#include "ft_printf_bonus.h"
#include <stdio.h>
#include <stdlib.h>

int	main() {
	int test = 1;
	printf("personal test -----------------------\n");
	printf("real printf =========================\n");
	printf("print result: \n");
	printf("value : %d\n", printf("%#.x\n", 0));
	printf("nbrlen test: %d\n", ft_nbrlen(-31, 10));
}