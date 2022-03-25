/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:25:52 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/25 17:25:05 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0) {
	std::cout << "Default constructor called." << std::endl;
	return ;
}

Fixed::Fixed(Fixed const &src) {
	std::cout << "Copy constructor called." << std::endl;
	*this = src;
}

Fixed::Fixed(int const nb) : _rawBits(nb << 8) {
	std::cout << "Int constructor called." << std::endl;
}

Fixed::Fixed(float const f) : _rawBits((int) roundf(f * 256)){
	std::cout << "Float constructor called." << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called." << std::endl;
	return ;
}

Fixed & Fixed::operator=(Fixed const & right) {
	std::cout << "Copy assignment operator called." << std::endl;
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
	
	int	v = 0;
	int	lv = this->_rawBits;
	int	rv = right._rawBits;

	while (rv > 0) {
		if (rv & 1)
			v += lv;
		lv <<= 1;
		rv >>= 1;
	}
	
	Fixed res;
	res.setRawBits(v >> this->_fractionalBits);
	return (res);

}

Fixed	Fixed::operator/(Fixed const & right) {

	int	v = 0;
	int	tmp = 1;
	int	lv = this->_rawBits;
	int	rv = right._rawBits;
	
	while (rv <= lv) {
		rv <<= 1;
		tmp <<= 1;
	}
	while (tmp > 1) {
		rv >>= 1;
		tmp >>= 1;
		if (lv >= rv) {
			lv -= rv;
			v += tmp;
		}
	}
	
	Fixed res(v);
	return (res);
}

Fixed&	Fixed::operator++(void) {
	this->_rawBits++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	res = *this;
	++*this;
	return (res);
}

Fixed&	Fixed::operator--(void) {
	this->_rawBits--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	res = *this;
	--*this;
	return (res);
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawbits member function called." << std::endl;
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

Fixed const &	Fixed::min(Fixed const & left, Fixed const & right) {
	if ((Fixed) left < (Fixed) right)
		return (left);
	return (right);
}

Fixed&	Fixed::min(Fixed &left, Fixed &right) {
	if (left < right)
		return (left);
	return (right);
}

Fixed const &	Fixed::max(Fixed const & left, Fixed const & right) {
	if ((Fixed) left > (Fixed) right)
		return (left);
	return (right);
}

Fixed&	Fixed::max(Fixed &left, Fixed &right) {
	if (left > right)
		return (left);
	return (right);
}