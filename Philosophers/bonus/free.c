/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:22:41 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/13 19:22:42 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_b.h"

void	free_everything(t_philo *p, pid_t *pid, t_starve *s, t_arg args)
{
	int	i;

	i = 0;
	while (i < args.p_nb)
		free(p[i++].last_meal);
	free(s);
	free(p);
	free(pid);
}
