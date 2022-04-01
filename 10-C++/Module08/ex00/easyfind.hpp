/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:27:33 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/01 18:05:00 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <list>
#include <map>
#include <vector>

bool	compare(int n1, int n2) {
	return (!static_cast<bool>(n1 - n2));
}

template<typename T>
T easyfind(T c, int n) {
	T = find_if(c.begin(), c.end(), compare());

}