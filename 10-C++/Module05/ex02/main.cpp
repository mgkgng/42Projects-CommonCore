/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:35:16 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/29 19:42:03 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main() {


	std::cout << std::endl << "\033[1;34m** test 1 : Shrubbery SUCCESS **\033[0m" << std::endl;		
	try {
		Bureaucrat b("BB", 25);

		ShrubberyCreationForm shru("COUCOU");
	
		b.signForm(shru);
		b.executeForm(shru);

	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "\033[1;34m** test 2 : Shrubbery FAIL **\033[0m" << std::endl;		
	try {
		Bureaucrat b("BB", 147);

		ShrubberyCreationForm shru("COUCOU");
	
		b.signForm(shru);
		b.executeForm(shru);

	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "\033[1;34m** test 3 : Robotomy SUCCESS **\033[0m" << std::endl;		
	try {
		Bureaucrat b("BB", 2);

		RobotomyRequestForm robo("COUCOU");
	
		b.signForm(robo);
		b.executeForm(robo);

	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	
	}
	
	std::cout << std::endl << "\033[1;34m** test 4 : Robotomy FAIL **\033[0m" << std::endl;		
	try {
		Bureaucrat b("BB", 72);

		RobotomyRequestForm robo("COUCOU");
	
		b.signForm(robo);
		b.executeForm(robo);
		
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "\033[1;34m** test 5 : President SUCCESS **\033[0m" << std::endl;		
	try {
		Bureaucrat b("BB", 5);

		PresidentialPardonForm president("COUCOU");
	
		b.signForm(president);
		b.executeForm(president);
		
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "\033[1;34m** test 6 : President FAIL **\033[0m" << std::endl;		
	try {
		Bureaucrat b("BB", 20);

		PresidentialPardonForm president("COUCOU");
	
		b.signForm(president);
		b.executeForm(president);
		
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}