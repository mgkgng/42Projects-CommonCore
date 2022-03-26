/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 23:51:07 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/26 22:57:44 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {

	std::cout << std::endl << "\033[1;34m** test 1 : Creating a fragtrap object **\033[0m" << std::endl;
	FragTrap Tom("Tom");

	std::cout << std::endl << "\033[1;34m** test 2 : make the fragtrap object attack **\033[0m" << std::endl;
	Tom.attack("Jerry");
	Tom.attack("Micky");
	Tom.attack("Goopy");

	std::cout << std::endl << "\033[1;34m** test 3 : make the fragtrap take damage **\033[0m" << std::endl;
	Tom.takeDamage(2);
	Tom.takeDamage(2);
	Tom.takeDamage(2);

	std::cout << std::endl << "\033[1;34m** test 4 : make the fragtrap get repaired **\033[0m" << std::endl;
	Tom.beRepaired(1);
	Tom.beRepaired(1);

	std::cout << std::endl << "\033[1;34m** test 5 : make the fragtrap activate its special function **\033[0m" << std::endl;
	Tom.highFivesGuys();

	std::cout << std::endl << "\033[1;34m** test 6 : Destructor called with return **\033[0m" << std::endl;

	return (0);
}