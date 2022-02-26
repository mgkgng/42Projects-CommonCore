/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:04:37 by min-kang          #+#    #+#             */
/*   Updated: 2021/10/24 22:07:16 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*begin;

	begin = *alst;
	if (begin == NULL)
	{
		*alst = new;
		return ;
	}
	while (begin->next)
		begin = begin->next;
	begin->next = new;
}
