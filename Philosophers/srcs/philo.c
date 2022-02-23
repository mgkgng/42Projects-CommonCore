/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:04:21 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/23 12:15:08 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_m.h"

void	thm_initiate(t_thm *thm, t_arg args)
{
	int	i;

	thm->th = ft_calloc(args.p_nb, sizeof(pthread_t));
	thm->m = ft_calloc(args.p_nb, sizeof(pthread_mutex_t));
	thm->done = ft_calloc(1, sizeof(pthread_mutex_t));
	i = 0;
	while (i < args.p_nb)
		pthread_mutex_init(&thm->m[i++], NULL);
	pthread_mutex_init(thm->done, NULL);
}

t_philo	*create_philo(t_thm thm, t_over over, t_arg args)
{
	t_philo	*philo;
	int		i;

	i = -1;
	philo = ft_calloc(args.p_nb, sizeof(t_philo));
	while (++i < args.p_nb)
	{
		philo[i].id = i;
		philo[i].t_die = args.t_die;
		philo[i].t_eat = args.t_eat;
		philo[i].t_sleep = args.t_sleep;
		philo[i].last_meal = &over.last_meal[i];
		if (args.e_max)
		{
			philo[i].e_max = args.e_max;
			philo[i].e_nb = &over.e_nb;
		}
		philo[i].done = thm.done;
		philo[i].f_l = &thm.m[i];
		philo[i].f_r = &thm.m[(i + 1) % args.p_nb];
		philo[i].start = over.start;
	}
	return (philo);
}

void	launch_philo(t_philo *philo, t_thm thm, t_over over, t_arg args)
{
	int			i;
	pthread_t	th_die;
	int			*enough;

	pthread_mutex_lock(thm.done);
	pthread_create(&th_die, NULL, &gameover, &over);
	pthread_detach(th_die);
	i = -1;
	while (++i < args.p_nb)
		pthread_create(&thm.th[i], NULL, &eat_sleep_think, &philo[i]);
	i = 0;
	while (i < args.p_nb)
		pthread_detach(thm.th[i++]);
	pthread_mutex_lock(thm.done);
}

void	philosophers(t_arg args)
{
	t_philo	*philo;
	t_over	over;
	t_thm	thm;

	thm_initiate(&thm, args);
	over = gameover_initialise(thm, args);
	philo = create_philo(thm, over, args);
	launch_philo(philo, thm, over, args);
	free_n_destroy(thm, philo, over);
}
