/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:08:24 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/21 16:45:24 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	karenFilter(std::string s) {
	
	std::string level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	size_t		i;
	for (i = 0; i < 4; i++)
		if (s == level[i])
			break;
	int	msg = i;
	
	Karen k;
	switch (msg) {
		case DEBUG :
			std::cout << std::endl << "[ DEBUG ]" << std::endl;
			k.complain("DEBUG");
			std::cout << std::endl;
		case INFO :
			std::cout << std::endl << "[ INFO ]" << std::endl;
			k.complain("INFO");
			std::cout << std::endl;
		case WARNING :
			std::cout << std::endl << "[ WARNING ]" << std::endl;
			k.complain("WARNING");
			std::cout << std::endl;
		case ERROR :
			std::cout << std::endl << "[ ERROR ]" << std::endl;
			k.complain("ERROR");
			std::cout << std::endl;
			break;
		default :
			std::cout << std::endl << "[ Probably complaining about insignificant problems ]" << std::endl;
			std::cout << std::endl;
	}
	return (0);
}

int	main(int argc, char **argv) {
	
	if (argc != 2)
		return (1);
	return (karenFilter(argv[1]));
}