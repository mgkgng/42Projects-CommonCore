/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 09:42:42 by gphilipp          #+#    #+#             */
/*   Updated: 2022/01/03 10:15:41 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(const char *str)
{
	if (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
	{
		return (1);
	}
	return (0);
}

static int	char_is_numeric(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi_length(const char *str)
{
	char	*pt_str;
	int		num;

	num = 0;
	pt_str = (char *) str;
	while (*str != '\0' && ft_isspace(str))
		str++;
	if (*str != '\0' && (*str == '+' || *str == '-'))
		str++;
	if (*str == '\0')
		return (0);
	while (*str != '\0' && char_is_numeric(*str) == 1 && ++num)
		str++;
	while (num && *str != '\0' && ft_isspace(str))
		str++;
	return (str - pt_str);
}

long int	ft_atoi(const char *str)
{
	long int		nb;
	long int		sign;

	nb = 0;
	sign = 1;
	while (*str != '\0' && ft_isspace(str))
	{
		str++;
	}
	if (*str != '\0' && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str != '\0' && char_is_numeric(*str) == 1)
	{
		nb *= 10;
		nb += *str - '0';
		str++;
	}
	return (nb * sign);
}
