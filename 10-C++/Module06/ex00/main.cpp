/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:22:59 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/30 00:31:32 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.hpp"

int	main(int argc, char **argv) {
	
	if (argc == 1) {
		std::cerr << "Error: the program needs an argument." << std::endl;
		return (1);
	} else if (argc > 2) {
		std::cerr << "Error: More than one argument." << std::endl;
		return (2);
	}

	std::string arg = static_cast<std::string>(argv[1]);

	if (!check_displayable(arg)) {
		std::cerr << "Error: Non displayable character found." << std::endl;
		return (3);
	}

	std::cout << is_double(arg) << std::endl;
	/*
	if (is_char(arg)) {
		
	} else if (is_int(arg)) {
		
	} else if (is_float(arg)) {
		
	} else if (is_double(arg)) {
		
	} else {
		std::cerr << "Error: type does not match." << std::endl;
		return (4);
	}*/
	return (0);
}