/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:04:03 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/18 21:14:39 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(int argc, char **argv)
{

	if (argc != 1)
		return 1;

	std::string input;
	std::string	add = "ADD", search = "SEARCH", exit = "EXIT";
	PhoneBook	phbk;

	while (1) {
		std::cout << "TYPE YOUR COMMAND (ADD / SEARCH / EXIT): ";
		std::cin >> input;
		if (!add.compare(input))
			phbk.saveContact();
		else if (!search.compare(input))
			phbk.showContact();
		else if (!exit.compare(input))
			return 0;
		else if (std::cin)
			std::cout << input << " is not a right command." << std::endl;
	}
		return 0;
}