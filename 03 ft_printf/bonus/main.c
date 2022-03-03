#include "ft_printf_bonus.h"
#include <stdio.h>
#include <stdlib.h>

int	main() {
	int test = 1;
	printf("personal test -----------------------\n");
	printf("real printf =========================\n");
	printf("print result: \n");
	printf("value : %d\n", printf("%10c\n", 0));
	printf("my printf ===========================\n");
	printf("print result: \n");
	printf("valeur : %d\n", ft_printf("%10c\n", 0));
}