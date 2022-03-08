/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:40:56 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/08 12:09:52 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int 	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		find_endl(char *s);
char	*ft_strndup(char *s, int len);
char	*ft_cut(char *s, int start);

#endif
