/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:09:20 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/31 14:29:44 by min-kang         ###   ########.fr       */
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

	try {
		Scalar scalar(arg);
		std::cout << scalar;
		
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}