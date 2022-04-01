/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:27:33 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/01 21:47:45 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <list>
#include <map>
#include <vector>
#include <stdexcept>

class NbNotFound : public std::exception {
	public:
		const char*	what() const throw() {return ("Number not found.");}
};

template<typename T>
typename T::iterator easyfind(T& c, int n) {
	typename T::iterator res = find(c.begin(), c.end(), n);
	if (res == c.end())
		throw NbNotFound();
	return (res);
}