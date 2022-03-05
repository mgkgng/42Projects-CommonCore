#include "ft_printf_bonus.h"
#include <stdio.h>
#include <stdlib.h>

int	main() {
	int test = 1;
	printf("personal test -----------------------\n");
	printf("real printf =========================\n");
	printf("print result: \n");
	printf("value : %d\n", printf("%0#10x\n", 155));
}