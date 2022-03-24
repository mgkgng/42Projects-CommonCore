/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 08:20:03 by gkgpteam          #+#    #+#             */
/*   Updated: 2022/01/15 08:28:16 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	list_free_keyval(void *data)
{
	t_keyval		*keyval;

	keyval = (t_keyval *)data;
	free(keyval->key);
	free(keyval->val);
	free(keyval);
}
