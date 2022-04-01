/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:37:33 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/01 16:39:40 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main() {
	std::vector<int> v;

	v.push_back(2);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);
	v.push_back(11);

	easyfind(v, 7);
}