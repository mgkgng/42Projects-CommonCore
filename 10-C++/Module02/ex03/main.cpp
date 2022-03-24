/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:29:41 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/24 23:51:33 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const p);

int	main(void) {
	Point	a(0.0f, 0.0f);
	Point	b(6.0f, 0.0f);
	Point	c(3.0f, 6.0f);

	std::cout << b.getX() << "+++++++++++++++++++++++++++++++++++" << std::endl;
	Point	test(1, 0.1f);
	std::cout << bsp(a, b, c, test) << std::endl;

	std::cout << "too weird" << c.getX() << std::endl;
}