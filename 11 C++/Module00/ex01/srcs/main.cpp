/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:04:03 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/18 12:04:19 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(int argc, char **argv)
{
	std::string	add = "ADD", search = "SEARCH", exit = "EXIT";
	PhoneBook	phbk;

	if (argc != 1)
		return 1;
	while (1) {
		std::string input;
		std::cout << "TYPE YOUR COMMAND: ";
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
	}
		return 0;
}