/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:45:57 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/04 22:01:21 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printstr(char *s, int precis)
{
	int	i;
	
	if (precis == -1)
		precis = ft_strlen(s);
	i = 0;
	while (s[i] && i < precis)
		ft_putchar(s[i++]);
	return (i);
}

int	print_s(char *s, t_spec spec)
{
	int	len;
	int	hyphen;
	char	*null_str;

	null_str = ft_strdup("(null)");
	if (!s)
		s = null_str;
	if (spec.width)
	{
		if (!(spec.flag % 2))
			len += ft_printstr(s, spec.precis);
		len += print_width(spec.width, ft_strlen(s) - spec.precis);
		if (spec.flag % 2)
			len += ft_printstr(s, spec.precis);
	}
	else
		len += ft_printstr(s, spec.precis);
	free(null_str);
	return (len);
}