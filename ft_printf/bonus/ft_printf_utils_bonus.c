/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:16:27 by min-kang          #+#    #+#             */
/*   Updated: 2021/11/17 13:24:05 by min-kang         ###   ########.fr       */
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
	if (!s)
		ft_putstr("(null)");
	while (s[i])
		ft_putchar((int) s[i++]);
}

char	*char_to_string(int c)
{
	char	*result;

	if (c == 0)
		return (ft_strdup(""));
	result = malloc(2);
	result[0] = (char) c;
	result[1] = '\0';
	return (result);
}

char	*ft_itoa_base(unsigned int n, char *base)
{
	int					i;
	int					count;
	unsigned int		save;
	char				*result;

	i = 0;
	save = n;
	count = 1;
	while (save > (unsigned int) ft_strlen(base) - 1)
	{
		count++;
		save /= (unsigned int) ft_strlen(base);
	}
	result = malloc(count + 1);
	result[count--] = '\0';
	while (n > (unsigned int) ft_strlen(base) - 1)
	{
		result[count--] = base[n % (unsigned int) ft_strlen(base)];
		n /= (unsigned int) ft_strlen(base);
	}
	result[count] = base[n % (unsigned int) ft_strlen(base)];
	return (result);
}

char	*ft_ltoa_base(unsigned long int n, char *base)
{
	int					i;
	int					count;
	unsigned long int	save;
	char				*result;

	i = 0;
	save = n;
	count = 1;
	while (save > (unsigned long int) ft_strlen(base) - 1)
	{
		count++;
		save /= (unsigned long int) ft_strlen(base);
	}
	result = malloc(count + 1);
	result[count--] = '\0';
	while (n > (unsigned long int) ft_strlen(base) - 1)
	{
		result[count--] = base[n % (unsigned long int) ft_strlen(base)];
		n /= (unsigned long int) ft_strlen(base);
	}
	result[count] = base[n % (unsigned long int) ft_strlen(base)];
	return (result);
}
