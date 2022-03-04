/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:45:57 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/04 17:53:17 by min-kang         ###   ########.fr       */
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

	// flag ' '
	len = 0;
	hyphen = 0;
	null_str = ft_strdup("(null)");
	if (!s)
		s = null_str;
	if (ft_strchr(spec.flag, '-'))
		hyphen = 1;
	if (spec.width)
	{
		if (hyphen)
			len += ft_printstr(s, spec.precis);
		len += print_width(spec.width, ft_strlen(s) - spec.precis);
		if (!hyphen)
			len += ft_printstr(s, spec.precis);
	}
	else
		len += ft_printstr(s, spec.precis);
	free(null_str);
	return (len);
}