/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:43:51 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/23 12:26:52 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_b.h"

void	*gameover(void *arg)
{
	t_over	*over;
	double		now;

	over = (t_over *) arg;
	while (1)
	{
		now = get_now(over->start);
		if (now - *(over->last_meal) >= over->t_die)
		{
			sem_wait(over->die_alone);
			printf("%.0f %d died\n", now, over->p_id);
			sem_post(over->game_over);
			exit(0);
		}
		usleep(100);
	}
}

t_over	*gameover_initialize(t_philo *philo, t_sem sem, t_arg args)
{
	t_over		*over;
	int				i;

	over = ft_calloc(args.p_nb, sizeof(t_over));
	i = -1;
	while (++i < args.p_nb)
	{
		over[i].p_id = i;
		over[i].p_nb = args.p_nb;
		over[i].t_die = args.t_die;
		over[i].last_meal = philo[i].last_meal;
		over[i].game_over = sem.game_over;
		over[i].die_alone = sem.die_alone;
		over[i].start = philo[i].start;
	}
	return (over);
}
