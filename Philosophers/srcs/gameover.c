/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameover.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:03:43 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/23 14:48:45 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_m.h"

int	gameover_check(t_over *over, double now)
{
	int	i;

	i = -1;
	while (++i < over->p_nb)
	{
		if (now - over->last_meal[i] >= over->t_die)
			return (i);
		usleep(100);
	}
	if (over->e_nb && over->e_nb == over->p_nb)
		return (INT32_MAX);
	return (-1);
}

void	*gameover(void *arg)
{
	t_over	*over;
	double	now;
	int		check;

	over = (t_over *) arg;
	while (1)
	{
		now = get_now(over->start);
		check = gameover_check(over, now);
		if (check >= 0)
		{
			if (check < INT32_MAX)
				printf("%.0f %d died\n", now, check);
			pthread_mutex_unlock(over->done);
			return (NULL);
		}
		usleep(100);
	}
}

t_over	gameover_initialise(t_thm thm, t_arg args)
{
	t_over			over;
	struct timeval	t;

	gettimeofday(&t, NULL);
	over.start = t.tv_sec * 1000 + t.tv_usec / 1000;
	over.p_nb = args.p_nb;
	over.t_die = args.t_die;
	over.last_meal = ft_calloc(args.p_nb, sizeof(double));
	over.done = thm.done;
	return (over);
}
