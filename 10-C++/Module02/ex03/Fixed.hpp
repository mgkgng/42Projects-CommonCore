/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:24:30 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/24 16:24:30 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <ostream>
#include <string>
#include <cmath>

class	Fixed {

	public:
		Fixed(void);
		Fixed(Fixed const &src);
		Fixed(int const nb);
		Fixed(float const nb);
		~Fixed(void);

		Fixed&	operator=(Fixed const & right);

		bool	operator>(Fixed const & right);
		bool	operator<(Fixed const & right);
		bool	operator>=(Fixed const & right);
		bool	operator<=(Fixed const & right);
		bool	operator==(Fixed const & right);
		bool	operator!=(Fixed const & right);

		Fixed	operator+(Fixed const & right);
		Fixed	operator-(Fixed const & right);
		Fixed	operator*(Fixed const & right);
		Fixed	operator/(Fixed const & right);

		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed&	min(Fixed const & left, Fixed const & right);
		static Fixed&	min(Fixed &left, Fixed &right);
		static Fixed&	max(Fixed const & left, Fixed const & right);
		static Fixed&	max(Fixed &left, Fixed &right);

	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;
	
};

std::ostream	&operator<<(std::ostream &out, Fixed const &right);