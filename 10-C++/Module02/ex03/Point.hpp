/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 01:17:31 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/24 20:50:49 by min-kang         ###   ########.fr       */
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

		float	getX(void) const;
		float	getY(void) const;
		Fixed	getFixedX(void) const;
		Fixed	getFixedY(void) const;

	private:
		Fixed const _x;
		Fixed const	_y;
		
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);