/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:17:17 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/23 12:23:07 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_m.h"

void	free_n_destroy(t_thm thm, t_philo *philo, t_over over)
{
	free(thm.th);
	pthread_mutex_destroy(thm.done);
	pthread_mutex_destroy(thm.m);
	free(thm.m);
	free(thm.done);
	free(over.last_meal);
	free(philo);
}
