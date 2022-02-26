/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 23:08:20 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/26 16:45:23 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(void) {
	std::ifstream input;
	std::ofstream output;
	std::string s1 = "lol", s2 = "yo";
	
	input.open("test");
	if (!input) {
		std::cout << "Cannot read the file" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string r;
	size_t	i;
	while (getline(input, r)) {
		if (i = find(r, s1))
		
			output << r;
			
	}
	input.close();
	output.close();
	return (0);
}