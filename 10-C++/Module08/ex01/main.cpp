/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 01:07:50 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/02 01:19:55 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
	Span test(5);
	
	std::cout << std::endl << "\033[1;34m** test 1 : trying to find a span with only one value **\033[0m" << std::endl;		
	test.addNumber(200);
	try {
		std::cout << test.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	test.addNumber(-101);
	test.addNumber(7);
	test.addNumber(6);
	test.addNumber(92);

	std::cout << std::endl << "\033[1;34m** test 2 : trying to find a span inside an array fully filled **\033[0m" << std::endl;		
	try {
		std::cout << test.longestSpan() << std::endl;
		std::cout << test.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "\033[1;34m** test 3 : trying to add another value into a fully filled array **\033[0m" << std::endl;		
	try {
		test.addNumber(2020);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
}