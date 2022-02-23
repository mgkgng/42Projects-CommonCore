/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:14:28 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/23 12:28:37 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_b.h"

t_philo	*create_philo(t_arg args)
{
	t_philo			*philo;
	struct timeval	t;
	double			start;
	int				i;

	gettimeofday(&t, NULL);
	start = t.tv_sec * 1000 + t.tv_usec / 1000;
	philo = ft_calloc(args.p_nb, sizeof(t_philo));
	i = -1;
	while (++i < args.p_nb)
	{
		philo[i].id = i;
		philo[i].t_die = args.t_die;
		philo[i].t_eat = args.t_eat;
		philo[i].t_sleep = args.t_sleep;
		philo[i].last_meal = ft_calloc(1, sizeof(double));
		philo[i].start = start;
		if (args.e_max)
			philo[i].e_nb = args.e_max;
	}
	return (philo);
}

void	*quit(void *arg)
{
	sem_t	*quit;

	quit = (sem_t *) arg;
	sem_wait(quit);
	exit(0);
}

void	launch_philo(t_philo *p, t_over *over, t_sem sem)
{
	pthread_t	th_die;
	pthread_t	th_quit;
	int			meal_nb;

	meal_nb = 0;
	pthread_create(&th_die, NULL, &gameover, (void *) over);
	pthread_create(&th_quit, NULL, &quit, (void *) sem.kill_all);
	pthread_detach(th_die);
	pthread_detach(th_quit);
	while (1)
		eat_sleep_think(p, sem, &meal_nb);
}

void	create_process(t_philo *philo, t_over *over, t_sem sem, t_arg args)
{
	int			i;
	pthread_t	th_end;
	pid_t		*pid;

	pid = ft_calloc(args.p_nb, sizeof(pid_t));
	i = -1;
	while (++i < args.p_nb)
	{
		pid[i] = fork();
		if (!pid[i])
			launch_philo(&philo[i], &over[i], sem);
	}
	sem_wait(sem.game_over);
	i = -1;
	while (++i < args.p_nb)
		sem_post(sem.kill_all);
	sem_terminate(&sem);
	free_everything(philo, pid, over, args);
}

void	philosophers(t_arg args)
{
	t_philo	*philo;
	t_sem	sem;
	t_over	*over;

	philo = create_philo(args);
	sem = sem_initialize(args);
	over = gameover_initialize(philo, sem, args);
	create_process(philo, over, sem, args);
}
