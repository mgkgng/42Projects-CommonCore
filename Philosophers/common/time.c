/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:21:25 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/11 16:22:07 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_c.h"

void	last_meal(double *last_meal, double start)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	*last_meal = t.tv_sec * 1000 + t.tv_usec / 1000 - start;
}

double	get_now(double start)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000 - start);
}
