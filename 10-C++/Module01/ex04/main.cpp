/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 23:08:20 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/23 11:23:43 by min-kang         ###   ########.fr       */
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

	size_t		i = r.find(s1);
	std::string	res;
	while (i != std::string::npos) {
		res += r.substr(0, i) + s2;
		r.erase(0, i + s1.length());
		i = r.find(s1);
	}
	if (r.length())
		res += r;

	std::ofstream output;
	output.open(filename + ".replace");
	output << res;

	input.close();
	output.close();

	return (0);

}