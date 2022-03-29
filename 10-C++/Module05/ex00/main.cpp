/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:44:46 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/29 15:49:58 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {

	std::cout << std::endl << "\033[1;34m** test 1 : trying to create with a too high grade **\033[0m" << std::endl;	
	try {
		Bureaucrat b1("b1", 0);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "\033[1;34m** test 2 : trying to create with a too low grade **\033[0m" << std::endl;	
	try {
		Bureaucrat b2("b2", 200);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "\033[1;34m** test 3 : trying to increase the grade too high **\033[0m" << std::endl;	
	try {
		Bureaucrat b3("b3", 1);
		b3.UpGrade();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "\033[1;34m** test 4 : trying to decrease the grade too low **\033[0m" << std::endl;	
	try {
		Bureaucrat b4("b4", 150);
		b4.DownGrade();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}