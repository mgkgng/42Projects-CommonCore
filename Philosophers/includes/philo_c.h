/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_c.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:29:58 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/23 11:59:41 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_C_H
# define PHILO_C_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_arg {
	int	p_nb;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	e_max;
}	t_arg;

/* parser */
t_arg	parser(int argc, char **argv);

/* time */
double	get_now(double start);

/* utils */
void	ft_putchar(char c);
void	ft_putstr(char *s);
int		ft_strlen(char *s);
int		ft_atoi(char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isdigit(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

/* error */
int		err_check(int argc, char **argv);

#endif
