/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:16:27 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/03 15:57:01 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		ft_putchar((int) s[i++]);
}

char	*to_string(int c)
{
	char	*result;

	result = malloc(2);
	result[0] = c;
	result[1] = '\0';
	return (result);
}

char	*hex(unsigned int n, int flag)
{
	int				i;
	int				count;
	unsigned int	save;
	char			*res;
	char			*hex;

	i = 0;
	save = n;
	count = 1;
	if (!flag)
		hex = ft_strdup("0123456789abcdef");
	else
		hex = ft_strdup("0123456789ABCDEF");
	while (save > (unsigned int) ft_strlen(hex) - 1)
	{
		count++;
		save /= (unsigned int) ft_strlen(hex);
	}
	res = malloc(count + 1);
	res[count--] = '\0';
	while (n > (unsigned int) ft_strlen(hex) - 1)
	{
		res[count--] = hex[n % (unsigned int) ft_strlen(hex)];
		n /= (unsigned int) ft_strlen(hex);
	}
	res[count] = hex[n % (unsigned int) ft_strlen(hex)];
	free(hex);
	return (res);
}

char	*ft_ltoa_base(unsigned long int n)
{
	int					i;
	int					count;
	unsigned long int	save;
	char				*res;
	char				*hex;

	i = 0;
	save = n;
	count = 1;
	hex = ft_strdup("0123456789abcdef");
	while (save > (unsigned long int) ft_strlen(hex) - 1)
	{
		count++;
		save /= (unsigned long int) ft_strlen(hex);
	}
	res = malloc(count + 1);
	res[count--] = '\0';
	while (n > (unsigned long int) ft_strlen(hex) - 1)
	{
		res[count--] = hex[n % (unsigned long int) ft_strlen(hex)];
		n /= (unsigned long int) ft_strlen(hex);
	}
	res[count] = hex[n % (unsigned long int) ft_strlen(hex)];
	free(hex);
	return (res);
}

char	*get_pointer(unsigned long int n)
{
	char	*add;
	char	*res;

	add = ft_ltoa_base(n);
	res = ft_strjoin("0x", add);
	free(add);
	return (res);
}