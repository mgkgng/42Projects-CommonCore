/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:26:09 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/23 22:11:33 by min-kang         ###   ########.fr       */
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

		int		operator+(Fixed const & right);
		int		operator-(Fixed const & right);
		int		operator*(Fixed const & right);
		int		operator/(Fixed const & right);

		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;
	
};

std::ostream	&operator<<(std::ostream &out, Fixed const &right);