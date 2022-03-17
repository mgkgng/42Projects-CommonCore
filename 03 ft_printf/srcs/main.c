#include "ft_printf.h"
#include <stdio.h>

int main()
{
	printf("%d\n", printf("%"));
	printf("===========\n");
	printf("%d\n", ft_printf("%"));
}