/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:04:03 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/18 17:49:47 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

1.	SETW
2.	EOF
3.	PRIVATE

int main(int argc, char **argv)
{

	if (argc != 1)
		return 1;

	std::string input;
	std::string	add = "ADD", search = "SEARCH", exit = "EXIT";
	PhoneBook	phbk;

	while (input.eof()) {
		std::cout << "TYPE YOUR COMMAND (ADD / SEARCH / EXIT): ";
		std::cin >> input;
		if (!add.compare(input))
			phbk.saveContact();
		else if (!search.compare(input)) {
			phbk.showContact();
			if (phbk.size)
				phbk.showInfo();
		}
		else if (!exit.compare(input))
			return 0;
		else
			std::cout << input << " is not a right command." << std::endl;
	}
		return 0;
}