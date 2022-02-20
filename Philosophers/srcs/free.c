/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:17:17 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/11 16:17:36 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_m.h"

void	free_n_destroy(t_thm thm, t_philo *philo, t_starve starve)
{
	free(thm.th);
	pthread_mutex_destroy(thm.done);
	pthread_mutex_destroy(thm.m);
	free(thm.m);
	free(thm.done);
	free(starve.last_meal);
	free(philo);
}
