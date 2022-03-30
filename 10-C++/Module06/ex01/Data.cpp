/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:57:25 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/30 19:59:37 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() {
	std::cout << "Data default constructor called." << std::endl;
}

Data::Data(int n) : wtf(n) {
	std::cout << "Data number constructor called." << std::endl;
}

Data::Data(Data const &) {
	std::cout << "Data copy constructor called." << std::endl;
}

Data::~Data() {
	std::cout << "Data destructor called." << std::endl;
}

Data& Data::operator=(Data const & src) {
	this->wtf = src.wtf;
	return (*this);
}