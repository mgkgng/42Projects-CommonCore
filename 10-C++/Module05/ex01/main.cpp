/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:01:24 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/29 19:13:23 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main() {
	
	Bureaucrat b("b_example", 5);

	std::cout << std::endl << "\033[1;34m** test 1 : trying to sign with high enough level **\033[0m" << std::endl;		
	try {
		Form f1("f1", 10, 100);
		f1.beSigned(b);
		b.signForm(f1);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "\033[1;34m** test 2 : trying to sign with low level **\033[0m" << std::endl;		
	try {
		Form f2("f2", 3, 100);
		f2.beSigned(b);
		b.signForm(f2);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}