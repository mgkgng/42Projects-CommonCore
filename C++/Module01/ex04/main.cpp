/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 23:08:20 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/27 16:07:10 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(void) {
	std::ifstream input;
	std::ofstream output;
	std::string s1 = "lol", s2 = "yo";
	std::string filename = "fuck";

	input.open(filename);
	if (!input) {
		std::cout << "Cannot read the file" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string r;
	size_t i;
	output.open(filename + ".replace");
	while (getline(input, r)) {
		i = r.find(s1);
		while (i != std::string::npos) {
			r.erase(i, s1.length());
			r.insert(i, s2);
			i = r.find(s1);
		}
		output << r << std::endl;
		// should i have to be worried about \n?
	}
	input.close();
	output.close();
	return (0);
}