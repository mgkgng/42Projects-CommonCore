/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:09:20 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/31 13:47:30 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

int	main(int argc, char **argv) {
	
	if (argc == 1) {
		std::cerr << "Error: the program needs an argument." << std::endl;
		return (1);
	} else if (argc > 2) {
		std::cerr << "Error: More than one argument." << std::endl;
		return (2);
	}

	std::string arg = static_cast<std::string>(argv[1]);
	
	/*std::string s = "M";
	char c = s.at(0);
	float f = static_cast<float>(c);
	float z = static_cast<float>(f);
	char m = static_cast<char>(f);
	std::cout << c << std::endl;
	std::cout << f << std::endl;
	std::cout << z << std::endl;
	std::cout << m << std::endl;*/

	try {
		Scalar scalar(arg);
		std::cout << scalar;
		
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}