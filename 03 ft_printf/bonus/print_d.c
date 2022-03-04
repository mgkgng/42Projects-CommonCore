/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:41:13 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/04 17:53:32 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_s(char *s, t_spec spec)
{
	int	len;
	char	*null_str;

	// flag ' '
	len = 0;
	null_str = ft_strdup("(null)");
	if (!s)
		s = null_str;
	if (spec.width)
	{
		if (ft_strchr(spec.flag, '-'))
			len += ft_printstr(s, spec.precis);
		len += print_width(spec.width, ft_strlen(s) - spec.precis);
		if (!ft_strchr(spec.flag, '-'))
			len += ft_printstr(s, spec.precis);
	}
	else
		len += ft_printstr(s, spec.precis);
	free(null_str);
	return (len);
}