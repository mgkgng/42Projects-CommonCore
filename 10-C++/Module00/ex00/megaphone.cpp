/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:41:07 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/24 15:00:51 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		int i;
		std::string s;
		for (i = 1; i < argc; i++)
			s += (std::string) argv[i];
		for (i = 0; i < s.length(); i++)
			std::cout << (char) toupper(s[i]);
		std::cout << std::endl;
	}
	return 0;
}