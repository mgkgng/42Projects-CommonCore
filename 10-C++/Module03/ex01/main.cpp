/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:34:38 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/21 18:40:16 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main() {

	std::cout << std::endl << "\033[1;34m** test 1 : Creating a claptrap object **\033[0m" << std::endl;
	ScavTrap Tom("Tom");

	std::cout << std::endl << "\033[1;34m** test 2 : make the claptrap object attack **\033[0m" << std::endl;
	Tom.attack("Jerry");

	std::cout << std::endl << "\033[1;34m** test 3 : Destructor called with return **\033[0m" << std::endl;

	return (0);
}