/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:05:51 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/13 19:06:07 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_b.h"

void	eat_sleep_think(t_philo *p, t_sem sem, int *meal_nb)
{
	double	now;

	sem_wait(sem.forks);
	sem_wait(sem.forks);
	now = get_now(p->start);
	*(p->last_meal) = now;
	printf("%.0f %d has taken a fork\n", now, p->id);
	printf("%.0f %d has taken a fork\n", now, p->id);
	printf("%.0f %d is eating\n", now, p->id);
	*meal_nb += 1;
	if (p->e_nb && *meal_nb == p->e_nb)
		sem_post(sem.game_over);
	usleep(p->t_eat * 1000);
	sem_post(sem.forks);
	sem_post(sem.forks);
	printf("%.0f %d is sleeping\n", get_now(p->start), p->id);
	usleep(p->t_sleep * 1000);
	printf("%.0f %d is thinking\n", get_now(p->start), p->id);
}
