/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:37:33 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/02 20:12:43 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"

int	main() {
	std::vector<int> v;

	v.push_back(2);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);
	v.push_back(11);

	try {
		std::vector<int>::iterator it = (easyfind(v, 3));
		std::cout << "Value " << *it << " found at index " << it - v.begin() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}