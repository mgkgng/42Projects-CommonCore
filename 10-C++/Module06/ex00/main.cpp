/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:22:59 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/30 11:52:55 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.hpp"
#include "convert.hpp"

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

	void*	ptr;
	/*bool	*f1[4](std::string) = {&is_char, &is_int, &is_float, &is_double};
	void	*f2[4]*/
	if (is_char(arg)) {
		char c = std::stoi(arg);
		ptr = static_cast<void *>(&c);
	} else if (is_int(arg)) {
		int n = std::stoi(arg);
		ptr = static_cast<void *>(&n);
	} else if (is_float(arg)) {
		float f = std::stof(arg);
		ptr = static_cast<void *>(&f);
	} else if (is_double(arg)) {
		double d = std::stod(arg);
		ptr = static_cast<void *>(&d);
	} else {
		std::cerr << "Error: type does not match." << std::endl;
		return (4);
	}
	
	to_char(ptr);
	to_int(ptr);
	to_float(ptr);
	to_double(ptr);
	
	return (0);
}