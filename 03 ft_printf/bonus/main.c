#include "ft_printf_bonus.h"
#include <stdio.h>

int	main() {
	printf("personal test -----------------------\n");
	printf("real printf =========================\n");
	printf("print result: \n");
	printf("value : %d\n", printf("%d\n", 42));
	printf("my printf ===========================\n");
	printf("print result: \n");
	printf("valeur : %d\n", ft_printf("%d\n", 42));
}