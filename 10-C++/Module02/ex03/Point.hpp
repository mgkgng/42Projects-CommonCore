/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 01:17:31 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/24 17:23:58 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../ex02/Fixed.hpp"

class Point {

	public:
		Point(void);
		Point(float const x, float const y);
		Point(Point const &);
		~Point(void);

		Point&	operator=(Point const &);

		Fixed getX(void) const;
		Fixed getY(void) const;

	private:
		Fixed const _x;
		Fixed const	_y;
		
};