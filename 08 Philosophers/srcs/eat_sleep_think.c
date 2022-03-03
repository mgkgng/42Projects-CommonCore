/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:18:14 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/23 12:15:54 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_m.h"

void	eat(t_philo *p, int *meal_nb)
{
	double	now;

	pthread_mutex_lock(p->f_l);
	pthread_mutex_lock(p->f_r);
	now = get_now(p->start);
	*(p->last_meal) = now;
	printf("%.0f %d has taken a fork\n", now, p->id);
	printf("%.0f %d has taken a fork\n", now, p->id);
	printf("%.0f %d is eating\n", now, p->id);
	if (p->e_max && ++(*meal_nb) == p->e_max)
		*(p->e_nb) += 1;
	usleep(p->t_eat * 1000);
	pthread_mutex_unlock(p->f_l);
	pthread_mutex_unlock(p->f_r);
}

void	sleep_think(t_philo *p)
{
	printf("%.0f %d is sleeping\n", get_now(p->start), p->id);
	usleep(p->t_sleep * 1000);
	printf("%.0f %d is thinking\n", get_now(p->start), p->id);
}

void	*eat_sleep_think(void *arg)
{
	t_philo			*p;
	int				meal_nb;
	int				i;

	p = (t_philo *) arg;
	meal_nb = 0;
	while (1)
	{
		eat(p, &meal_nb);
		sleep_think(p);
	}
	return (NULL);
}
