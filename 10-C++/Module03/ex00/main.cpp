/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:15:57 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/21 17:06:44 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
int main() {

	std::cout << std::endl << "\033[1;34m** test 1 : Creating a claptrap object **\033[0m" << std::endl;
	ClapTrap Tom("Tom");

	std::cout << std::endl << "\033[1;34m** test 2 : make the claptrap object attack **\033[0m" << std::endl;
	Tom.attack("Jerry");

	std::cout << std::endl << "\033[1;34m** test 3 : Destructor called with return **\033[0m" << std::endl;

	return (0);
}