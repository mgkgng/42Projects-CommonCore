/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:22:59 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/30 23:17:53 by min-kang         ###   ########.fr       */
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
	
	float a = 0.0;
	std::cout << a << "lololo" << std::endl;

	try {
		Scalar scalar(arg);
		std::cout << scalar;
		
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}