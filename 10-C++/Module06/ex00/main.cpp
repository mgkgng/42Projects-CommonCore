/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:22:59 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/29 23:37:13 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

bool	check_displayable(std::string s) {
	for (int i = 0; i < s.length(); i++)
		if (!isprint(s.at(i)))
			return (false);
	return (true);
}

bool	is_char(std::string s) {
	return (s.length() == 1 && !isdigit(s.at(0))) ? true : false;
}

bool	is_int(std::string s) {
	
}

bool	is_float(std::string s) {
	
}

bool	is_double(std::string s) {
	
}

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
	}
	if (is_char(arg))
}