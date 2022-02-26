/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:50:36 by min-kang          #+#    #+#             */
/*   Updated: 2021/11/17 14:31:52 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_flag
{
	char	*flags;
	int		index;
}	t_flag;

typedef struct s_value
{
	int	value;
	int	index;
}	t_value;

typedef struct s_wp
{
	int	w_value;
	int	w_index;
	int	p_value;
	int	p_index;
}	t_wp;

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
t_value	*print_factory(int i, const char *s, va_list arg_n);
int		print_and_return(char *arg, char convert, char *flags, t_wp *s_wp);
t_flag	*ft_flag(const char *s, int i);
t_wp	*ft_width_min(const char *s, int i, t_wp *s_wp);
t_wp	*ft_precision(const char *s, int i, t_wp *s_wp);
int		ft_printf(const char *s, ...);
char	*char_to_string(int c);
char	*only_width_min(char *arg, int width_min);
char	*flag_converter(char *arg, char convert, char *flags, t_wp *s_wp);
t_arg	*ft_conversion(char convert, t_arg *arg, \
t_value *result, va_list arg_n);
char	*ft_precision_num(char *arg, int precision);
char	*ft_precision_str(char *arg, int precision);
char	*ft_strdup_printf(char *s);
int		make_it_shorter(char *arg, char convert);

#endif
