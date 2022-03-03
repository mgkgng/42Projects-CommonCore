/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:55:16 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/27 14:44:37 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_chr_count(char *s, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (s[++i])
		if (s[i] == c)
			count++;
	return (count);
}

char	*ft_strcat(char *s, char c)
{
	char	*new;
	int		i;

	if (!s)
	{
		new = ft_calloc(2, sizeof(char));
		new[0] = c;
		new[1] = '\0';
		return (new);
	}
	new = ft_calloc(ft_strlen(s) + 2, sizeof(char));
	i = -1;
	while (s[++i])
		new[i] = s[i];
	new[i++] = c;
	new[i] = '\0';
	free(s);
	return (new);
}

static int	count_int(int n)
{
	int	count;

	count = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 9)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	int		count;

	count = count_int(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	result = malloc(count + 1);
	if (!result)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		result[i++] = '-';
		n *= -1;
	}
	result[count--] = '\0';
	while (count >= i)
	{
		result[count--] = n % 10 + '0';
		n /= 10;
	}
	return (result);
}
