/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:43:51 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/23 13:38:54 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_b.h"

void	*die(void *arg)
{
	t_starve	*starve;
	double		now;

	starve = (t_starve *) arg;
	while (1)
	{
		now = get_now(starve->start);
		if (now - *(starve->last_meal) >= starve->t_die)
		{
			sem_wait(starve->die_alone);
			printf("%.0f %d died\n", now, starve->p_id);
			sem_post(starve->game_over);
			exit(0);
		}
		usleep(100);
	}
}

t_starve	*die_initialize(t_philo *philo, t_sem sem, t_arg args)
{
	t_starve		*starve;
	int				i;

	starve = ft_calloc(args.p_nb, sizeof(t_starve));
	i = -1;
	while (++i < args.p_nb)
	{
		starve[i].p_id = i;
		starve[i].p_nb = args.p_nb;
		starve[i].t_die = args.t_die;
		starve[i].last_meal = philo[i].last_meal;
		starve[i].game_over = sem.game_over;
		starve[i].die_alone = sem.die_alone;
		starve[i].start = philo[i].start;
	}
	return (starve);
}
