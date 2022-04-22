/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameover.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:37:53 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/23 14:33:37 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_b.h"

void	*quit(void *arg)
{
	sem_t	*gameover;

	gameover = (sem_t *) arg;
	usleep(100);
	sem_wait(gameover);
	exit(0);
}

void	*enough(void *arg)
{
	t_sem	*sem;
	int		i;

	sem = (t_sem *) arg;
	i = 0;
	while (i++ < sem->p_nb)
		sem_wait(sem->enough);
	sem_post(sem->game_over);
	return (NULL);
}
