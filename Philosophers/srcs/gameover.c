/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameover.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:03:43 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/23 12:24:08 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_m.h"

void	*gameover(void *arg)
{
	t_over	*over;
	int		i;
	double	now;

	over = (t_over *) arg;
	while (1)
	{
		now = get_now(over->start);
		i = -1;
		while (++i < over->p_nb)
		{
			if (now - over->last_meal[i] >= over->t_die)
			{
				printf("%.0f %d died\n", now, i);
				pthread_mutex_unlock(over->done);
				return (NULL);
			}
			usleep(100);
		}
		if (over->e_nb == over->p_nb)
		{
			pthread_mutex_unlock(over->done);
			return (NULL);
		}
		usleep(100);
	}
}

t_over	gameover_initialise(t_thm thm, t_arg args)
{
	t_over		over;
	struct timeval	t;

	gettimeofday(&t, NULL);
	over.start = t.tv_sec * 1000 + t.tv_usec / 1000;
	over.p_nb = args.p_nb;
	//over.e_nb = ft_calloc(1, sizeof(int));
	over.t_die = args.t_die;
	over.last_meal = ft_calloc(args.p_nb, sizeof(double));
	over.done = thm.done;
	return (over);
}
