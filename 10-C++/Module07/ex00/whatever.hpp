/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:34:44 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/01 16:24:09 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template<typename T>
void	swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T& min(T& a, T& b) {
	return ((a < b) ? a : b);
}

template<typename T>
T&	max(T& a, T& b) {
	return ((a > b) ? a : b);
}