/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_b.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:28:09 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/13 19:10:29 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_B_H
# define PHILO_B_H

# include <semaphore.h>
# include <signal.h>
# include "philo_c.h"
# define FORKS "/forks"
# define GAMEOVER "/game_over"
# define KILLALL "/kill_all"

typedef struct s_philo {
	int		id;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		e_nb;
	sem_t	*forks;
	double	start;
	double	*last_meal;
}	t_philo;

typedef struct s_starve {
	int		p_nb;
	int		p_id;
	int		t_die;
	double	start;
	double	*last_meal;
	sem_t	*game_over;
}	t_starve;

typedef struct s_sem {
	sem_t	*forks;
	sem_t	*game_over;
	sem_t	*kill_all;
}	t_sem;

/* philosophers */
void		philosophers(t_arg args);

/* do */
void		*die(void *arg);
t_starve	*die_initialize(t_philo *philo, sem_t *game_over, t_arg args);
void		eat_sleep_think(t_philo *p, t_sem sem, int *meal_nb);

/* sem */
t_sem		sem_initialize(t_arg args);
void		sem_terminate(t_sem *sem);

/* free */
void		free_everything(t_philo *p, pid_t *pid, t_starve *s, t_arg args);

#endif
