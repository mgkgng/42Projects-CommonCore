/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 23:08:20 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/22 18:56:17 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ios>

int main(int argc, char **argv) {

	if (argc != 4) {
		std::cout << "Error: Wrong number of arguments." << std::endl;
		return (1);
	}

	std::ifstream input;
	std::string s1 = argv[2], s2 = argv[3];
	std::string filename = argv[1];

	if (!filename.length() || !s1.length() || !s2.length()) {
		std::cout << "Error: Wrong argument." << std::endl;
		return (2);
	}

	input.open(filename);
	if (!input) {
		std::cout << "Cannot read the file" << std::endl;
		return (4);
	}

	std::string r;
	r = std::string((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());

	size_t		i;
	std::string	res;
	for (i = r.find(s1); i != std::string::npos; r = r.substr(i + s1.length(), r.length() - i))
		res += r.substr(0, i);

	std::ofstream output;
	output.open(filename + ".replace");
	output << r;

	input.close();
	output.close();

	return (0);

}