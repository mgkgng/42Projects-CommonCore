/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:29:41 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/25 17:21:33 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

void	print_res(bool res, Point const a, Point const b, Point const c, Point const p) {
	std::cout << "Point(" << p.getX() << ", " << p.getY() << ") ";
	if (res)
		std::cout << "is in the triangle ";
	else
		std::cout << "is not in the triangle ";
	std::cout	<< "A(" << a.getX() << ", " << a.getY() << "), B("
				<< b.getX() << ", " << b.getY() << "), C("
				<< c.getX() << ", " << c.getY() << ")." << std::endl;
}

bool	bsp(Point const a, Point const b, Point const c, Point const p);

int	main(void) {
	Point	a(0.0f, 0.0f);
	Point	b(6.0f, 0.0f);
	Point	c(3.0f, 6.0f);

	Point	test1(1.0f, 1.0f);
	Point	test2(3.0f, 6.0f);
	Point	test3(51.0f, 51.0f);

	print_res(bsp(a, b, c, test1), a, b, c, test1);
	print_res(bsp(a, b, c, test2), a, b, c, test2);
	print_res(bsp(a, b, c, test3), a, b, c, test3);
	

}