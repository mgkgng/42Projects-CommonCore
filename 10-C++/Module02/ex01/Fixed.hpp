/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:18:00 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/21 13:21:17 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cmath>

class	Fixed {

	public:
		Fixed(void);
		Fixed(Fixed const &src);
		Fixed(int const nb);
		~Fixed(void);

		Fixed	&operator=(Fixed const &rhs);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					n;
		static const int	f = 8;
	
};