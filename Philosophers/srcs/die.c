/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:03:43 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/11 16:19:00 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_m.h"

void	*die(void *arg)
{
	t_starve	*starve;
	int			i;
	double		now;

	starve = (t_starve *) arg;
	while (1)
	{
		now = get_now(starve->start);
		i = -1;
		while (++i < starve->p_nb)
		{
			if (now - starve->last_meal[i] >= starve->t_die)
			{
				printf("%.0f %d died\n", now, i);
				pthread_mutex_unlock(starve->done);
				return (NULL);
			}
			usleep(100);
		}
		usleep(100);
	}
}

t_starve	die_initialise(t_thm thm, t_arg args)
{
	t_starve		starve;
	struct timeval	t;

	gettimeofday(&t, NULL);
	starve.start = t.tv_sec * 1000 + t.tv_usec / 1000;
	starve.p_nb = args.p_nb;
	starve.t_die = args.t_die;
	starve.last_meal = ft_calloc(args.p_nb, sizeof(double));
	starve.done = thm.done;
	return (starve);
}
