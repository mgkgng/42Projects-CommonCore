/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:50:36 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/01 19:52:06 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_len
{
	int	length;
	int	index;
}	t_len;

typedef struct s_opt
{
	char	*flag;
	int		width;
	int		precis;
}	t_opt;

typedef struct s_arg
{
	char	*data;
	char	type;	
}	t_arg;

void	ft_putchar(int c);
void	ft_putstr(char *s);
char	*ft_itoa_base(unsigned int n, char *base);
char	*ft_ltoa_base(unsigned long int n, char *base);
char	*zero_flag(char *arg, int width_min);
char	*plus_flag(char *arg);
char	*space_flag(char *arg);
char	*hashtag_flag(char *arg, char convert);
char	*minus_flag(char *arg, int width_min);
char	*precision_app(char *arg, char convert, int precision);
t_len	print_factory(const char *s, int i, va_list arg_n);
int		print_and_return(char *arg, char convert, t_opt opt);
char	*get_flag(const char *s, int *i);
int		get_width(const char *s, int *i);
int		ft_precision(const char *s, int *i);
int		ft_printf(const char *s, ...);
char	*char_to_string(int c);
char	*only_width(char *arg, int width_min);
char	*flag_converter(char *arg, char convert, t_opt opt);
t_arg	*ft_conversion(char convert, t_len *result, va_list arg_n);
char	*ft_precision_num(char *arg, int precision);
char	*ft_precision_str(char *arg, int precision);
char	*ft_strdup_printf(char *s);
int		make_it_shorter(char *arg, char convert);

#endif
