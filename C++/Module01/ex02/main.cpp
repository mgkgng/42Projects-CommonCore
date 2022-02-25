/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:18:26 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/25 20:30:51 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void) {
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "==================first exercise=================" << std::endl;
	std::cout << "Address of the string value: " << &str << std::endl;
	std::cout << "Address displayed using PTR: " << stringPTR << std::endl;
	std::cout << "Address displayed using REF: " << &stringREF << std::endl;
	std::cout << "=================second exercise=================" << std::endl;
	std::cout << "String displayed using PTR: " << *stringPTR << std::endl;
	std::cout << "String displayed using REF: " << stringREF << std::endl;
	std::cout << "=================================================" << std::endl;

	return (0);
}