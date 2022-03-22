/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:08:24 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/22 14:54:43 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	HarlFilter(std::string s) {
	
	std::string level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	size_t		i;
	for (i = 0; i < 4; i++)
		if (s == level[i])
			break;
	int	msg = i;
	
	Harl h;
	switch (msg) {
		case DEBUG :
			std::cout << std::endl << "[ DEBUG ]" << std::endl;
			h.complain("DEBUG");
			std::cout << std::endl;
		case INFO :
			std::cout << std::endl << "[ INFO ]" << std::endl;
			h.complain("INFO");
			std::cout << std::endl;
		case WARNING :
			std::cout << std::endl << "[ WARNING ]" << std::endl;
			h.complain("WARNING");
			std::cout << std::endl;
		case ERROR :
			std::cout << std::endl << "[ ERROR ]" << std::endl;
			h.complain("ERROR");
			std::cout << std::endl;
			break;
		default :
			std::cout << std::endl << "[ Probably complaining about insignificant problems ]" << std::endl;
			std::cout << std::endl;
	}
	return (0);
}

int	main(int argc, char **argv) {
	
	if (argc < 2) {
		std::cout << std::endl << "Error: An argument is required." << std::endl << std::endl;
		return (1);
	}
	if (argc > 2) {
		std::cout << std::endl << "Error: Only one argument is required." << std::endl << std::endl;
		return (2);
	}
	return (HarlFilter(argv[1]));
}