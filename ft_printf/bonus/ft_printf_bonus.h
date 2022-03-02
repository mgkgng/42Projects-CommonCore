/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:50:36 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/02 14:11:59 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef enum e_convert {
	CONV_DI,
	CONV_U,
	CONV_XL,
	CONV_XU,
	CONV_S,
	CONV_C,
	CONV_P,
	CONV_PERC,
}	t_convert;

typedef struct s_opt
{
	char	*flag;
	int		width;
	int		precis;
}	t_opt;

typedef struct s_print
{
	char	*str;
	int		type;	
}	t_print;


/* flag */
void	zero(t_print *print, int width);
void	plus_space(t_print *print, char flag);
void	hashtag(t_print *print, int convert);
void	minus(t_print *print, int width);
char	*app_width(t_print *print, int width);
void	app_flag(t_print *print, t_opt opt);

/* precision */
void	app_precis(t_print *print, int precis);

/* print */
int		print_factory(const char *s, int *i, va_list arg_n);

/* get */
char	*get_flag(const char *s, int *i);
int		get_width(const char *s, int *i);
int		get_precis(const char *s, int *i);
char	*get_str(char type, va_list arg_n);
int		get_type(char type);

/* utils */
char	*to_string(int c);
void	ft_putchar(int c);
void	ft_putstr(char *s);
char	*ft_itoa_base(unsigned int n, int flag);
char	*ft_ltoa_base(unsigned long int n);
char	*get_pointer(unsigned long int n);

#endif
