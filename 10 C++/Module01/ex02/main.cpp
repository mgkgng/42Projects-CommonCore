/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:18:26 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/19 12:56:36 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void) {
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << std::endl << "\033[1;34m** test 1 : showing address of string, string-ptr and string-ref **\033[0m" << std::endl;
	std::cout << "Address of the string value: " << &str << std::endl;
	std::cout << "Address displayed using PTR: " << stringPTR << std::endl;
	std::cout << "Address displayed using REF: " << &stringREF << std::endl;

	std::cout << std::endl << "\033[1;34m** test 2 : showing the string by using string-ptr and string-ref **\033[0m" << std::endl;
	std::cout << "String displayed using PTR: " << *stringPTR << std::endl;
	std::cout << "String displayed using REF: " << stringREF << std::endl;

	std::cout << std::endl;

	return (0);
}