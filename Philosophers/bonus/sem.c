/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:09:40 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/22 16:47:33 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_b.h"

t_sem	sem_initialize(t_arg args)
{
	t_sem	sem;
	int		i;

	sem_unlink(FORKS);
	sem_unlink(GAMEOVER);
	sem_unlink(KILLALL);
	sem_unlink(DIEALONE);
	sem.forks = sem_open(FORKS, O_CREAT, 0644, args.p_nb);
	sem.game_over = sem_open(GAMEOVER, O_CREAT, 0644, 1);
	sem_wait(sem.game_over);
	sem.die_alone = sem_open(DIEALONE, O_CREAT, 0644, 1);
	sem.kill_all = sem_open(KILLALL, O_CREAT, 0644, args.p_nb);
	i = -1;
	while (++i < args.p_nb)
		sem_wait(sem.kill_all);
	return (sem);
}

void	sem_terminate(t_sem *sem)
{
	sem_close(sem->forks);
	sem_close(sem->game_over);
	sem_unlink(FORKS);
	sem_unlink(GAMEOVER);
}
