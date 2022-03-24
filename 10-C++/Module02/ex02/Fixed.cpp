/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:25:52 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/24 01:14:45 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const nb) : _rawBits(nb << 8) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const f) : _rawBits((int) roundf(f * 256)){
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed & Fixed::operator=(Fixed const & right) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawBits = right.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, Fixed const & right) {
	out << right.toFloat();
	return (out);
}

bool	Fixed::operator>(Fixed const & right) {
	return (this->getRawBits() > right.getRawBits());
}

bool	Fixed::operator<(Fixed const & right) {
	return (this->getRawBits() < right.getRawBits());
}

bool	Fixed::operator>=(Fixed const & right) {
	return (this->getRawBits() >= right.getRawBits());
}

bool	Fixed::operator<=(Fixed const & right) {
	return (this->getRawBits() <= right.getRawBits());
}

bool	Fixed::operator==(Fixed const & right) {
	return (this->getRawBits() == right.getRawBits());
}

bool	Fixed::operator!=(Fixed const & right) {
	return (this->getRawBits() != right.getRawBits());
}

Fixed	Fixed::operator+(Fixed const & right) {
	Fixed	res;
	res.setRawBits(this->getRawBits() + right.getRawBits());
	return (res);
}

Fixed	Fixed::operator-(Fixed const & right) {
	Fixed	res;
	res.setRawBits(this->getRawBits() + right.getRawBits());
	return (res);
}

Fixed	Fixed::operator*(Fixed const & right) {
	int	res = 0;
	int	leftv = this->getRawBits();
	int	rightv = right.getRawBits();

	while (rightv > 0) {
		if (rightv & 1)
			res += leftv;
		leftv = leftv << 1;
		rightv = rightv >> 1;
	}
	
	Fixed f;
	f.setRawBits(res / 256.0f);
	return (f);
}

Fixed	Fixed::operator/(Fixed const & right) {
	Fixed	res;
	res.setRawBits(this->getRawBits() + right.getRawBits());
	return (res);}

Fixed&	Fixed::operator++(void) {
	this->_rawBits += 1;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	res;
	res.setRawBits(this->getRawBits() + 1);
	return (res);
}

Fixed&	Fixed::operator--(void) {
	this->_rawBits -= 1 * pow(2, this->_fractionalBits);
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	res;
	res.setRawBits(this->getRawBits() - 1);
	return (res);
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawbits member function called" << std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits(int const raw) {
	this->_rawBits = raw;
}

float	Fixed::toFloat(void) const {
	return ( (float) this->_rawBits / 256.0f );
}

int	Fixed::toInt(void) const {
	return ( this->_rawBits / 256 );
}