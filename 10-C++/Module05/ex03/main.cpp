/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:44:29 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/30 12:36:21 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int	main() {

	Bureaucrat	b("Kafka", 3);
	Intern		poorIntern;


	std::cout << std::endl << "\033[1;34m** test 1 : Intern FAIL **\033[0m" << std::endl;		
	try {
		Form *f = poorIntern.makeForm("have make anything right now.", "toto");
		b.signForm(*f);
		b.executeForm(*f);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "\033[1;34m** test 2 : Intern SUCCESS **\033[0m" << std::endl;		
	try {
		Form* f = poorIntern.makeForm("shrubbery creation", "toto");
		b.signForm(*f);
		b.executeForm(*f);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}