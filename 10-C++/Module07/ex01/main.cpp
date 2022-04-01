/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 01:49:13 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/01 02:20:32 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cmath>
#include "iter.hpp"

void	test1(int n) {
	std::cout << pow(n, 3) << std::endl;
}

void	test2(float f) {
	std::cout << f * 3 << std::endl;
}

void	test3(std::string s) {
	for (int i = s.length() - 1; i >= 0; i--)
		std::cout << s.at(i);
	std::cout << std::endl;
}

int	main() {
	int			t1[] = {2, 3, 5, 7, 11};
	float		t2[] = {3.14f, 1.61803f, 2.718f, 4.6692f};
	std::string	t3[] = {"VENI", "VIDI", "VICI"};

	iter(t1, 5, &test1);
	iter(t2, 4, test2);
	iter(t3, 3, &test3);
}