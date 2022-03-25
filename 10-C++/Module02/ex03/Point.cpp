/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 01:20:45 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/25 17:12:56 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {
	std::cout << "Default constructor called." << std::endl;
}

Point::Point(float const x, float const y) : _x(Fixed(x)), _y(Fixed(y)) {
	std::cout << "Float constructor called." << std::endl;
}

Point::Point(Point const & right) {
	std::cout << "Copy constructor called." << std::endl;
	*this = right;
}

Point&	Point::operator=(Point const & right) {
	(Fixed &) this->_x = right.getFixedX();
	(Fixed &) this->_y = right.getFixedY();
	return (*this);
}

Point::~Point(void) {
	std::cout << "Destructor called." << std::endl;
}

float Point::getX(void) const {
	return (this->_x.toFloat());
}

float Point::getY(void) const {
	return (this->_y.toFloat());
}

Fixed	Point::getFixedX(void) const {
	return (this->_x);
}

Fixed	Point::getFixedY(void) const {
	return (this->_y);
}