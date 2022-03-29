/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:35:16 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/29 18:59:01 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main() {


	try {
		Bureaucrat b1("BB1", 144);
		Bureaucrat b2("BB2", 146);
		Bureaucrat b3("BB3", 130);

		ShrubberyCreationForm shru("COUCOU");

		shru.beSigned(b1);
		shru.beSigned(b2);
		shru.beSigned(b3);

	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat b4("BB5", 25);
		Bureaucrat b5("BB6", 100);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	
	}

	try {
		Bureaucrat b6("BB5", 25);
		Bureaucrat b7("BB6", 100);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

}