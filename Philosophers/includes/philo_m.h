/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_m.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:31:21 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/23 12:23:19 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_M_H
# define PHILO_M_H

# include "philo_c.h"

typedef struct s_philo {
	int				id;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				e_max;
	int				*e_nb;
	double			start;
	pthread_mutex_t	*f_l;
	pthread_mutex_t	*f_r;
	pthread_mutex_t	*done;
	double			*last_meal;
}	t_philo;

typedef struct s_thm {
	pthread_t		*th;
	pthread_mutex_t	*m;
	pthread_mutex_t	*done;
}	t_thm;

typedef struct s_over {
	int				p_nb;
	int				e_nb;
	int				t_die;
	double			start;
	double			*last_meal;
	pthread_mutex_t	*done;
}	t_over;

/* philosophers */
void		philosophers(t_arg args);

/* die */
void		*gameover(void *arg);
t_over		gameover_initialise(t_thm thm, t_arg args);
void		eat(t_philo *p, int *meal_nb);
void		sleep_think(t_philo *p);
void		*eat_sleep_think(void *arg);

/* free */
void		free_n_destroy(t_thm thm, t_philo *philo, t_over over);

#endif
