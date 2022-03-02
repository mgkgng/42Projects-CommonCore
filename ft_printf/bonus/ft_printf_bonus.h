/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:50:36 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/02 11:56:03 by min-kang         ###   ########.fr       */
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

typedef struct s_arg
{
	char	*print;
	int		type;	
}	t_arg;

void	ft_putchar(int c);
void	ft_putstr(char *s);
char	*ft_itoa_base(unsigned int n, int flag);
char	*ft_ltoa_base(unsigned long int n);
char	*zero_flag(char *arg, int width_min);
char	*plus_flag(char *arg);
char	*space_flag(char *arg);
char	*hashtag_flag(char *arg, char convert);
char	*minus_flag(char *arg, int width_min);
char	*precision_app(char *arg, char convert, int precision);
int		print_factory(const char *s, int i, va_list arg_n);
int		print(t_arg arg, t_opt opt);
char	*get_flag(const char *s, int *i);
int		get_width(const char *s, int *i);
int		ft_precision(const char *s, int *i);
int		ft_printf(const char *s, ...);
char	*char_to_string(int c);
char	*only_width(char *arg, int width_min);
char	*flag_converter(char *arg, char convert, t_opt opt);
t_arg	*ft_conversion(char convert, t_len *result, va_list arg_n);
char	*app_precis_num(char *arg, int precis);
char	*app_precis_str(char *arg, int precis);
char	*ft_strdup_printf(char *s);
int		without_opt(t_arg arg);
char	*get_pointer(unsigned long int n);


#endif
