/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 23:08:20 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/20 13:08:05 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(void) {

	std::ifstream input;
	std::string s1 = "The Balrog", s2 = "Eric Zemmour";
	std::string filename = "Gandalf";

	input.open(filename);
	if (!input) {
		std::cout << "Cannot read the file" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string r;
	r = std::string((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());

	size_t	i = r.find(s1);
	while (i != std::string::npos) {
		r.erase(i, s1.length());
		r.insert(i, s2);
		i = r.find(s1);
	}

	std::ofstream output;
	output.open(filename + ".replace");
	output << r;

	input.close();
	output.close();

	return (0);
}