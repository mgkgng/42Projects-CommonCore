/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dep.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 12:39:59 by gphilipp          #+#    #+#             */
/*   Updated: 2022/01/07 10:32:56 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEP_H
# define DEP_H

int			ft_isspace(const char *str);
int			ft_atoi_length(const char *str);
long int	ft_atoi(const char *str);

char		*ft_get_content(char *path);

int			ft_intlen(const int n);
char		*ft_itoa(const int n, int *size);

int			ft_strlen(const char *s);

#endif