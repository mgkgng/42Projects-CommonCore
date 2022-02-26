/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 23:08:20 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/26 15:46:28 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(void) {
	std::ifstream input("test");
	std::ofstream output("test.replace");
	std::string s1 = "lol", s2 = "yo";
	
	std::cout << s1 << "-------" << s2 << std::endl;

}