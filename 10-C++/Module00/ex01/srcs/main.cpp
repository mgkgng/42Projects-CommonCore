/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:04:03 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/19 18:41:47 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(int argc, char **argv)
{

	if (argc != 1)
		return 1;

	std::string input;
	PhoneBook	phbk;

	do {
		std::cout << "TYPE YOUR COMMAND (ADD / SEARCH / EXIT): ";
		getline(std::cin, input);
		if (input == "ADD")
			phbk.saveContact();
		else if (input == "SEARCH")
			phbk.showContact();
		else if (input != "" && input != "EXIT")
			std::cout << input << " is not a right command." << std::endl;
	} while (input != "EXIT" && !std::cin.eof());
		return 0;
}