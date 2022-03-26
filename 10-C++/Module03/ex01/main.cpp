/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:34:38 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/26 22:58:12 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {

	std::cout << std::endl << "\033[1;34m** test 1 : Creating a scavtrap object **\033[0m" << std::endl;
	ScavTrap Tom("Tom");

	std::cout << std::endl << "\033[1;34m** test 2 : make the scavtrap object attack **\033[0m" << std::endl;
	Tom.attack("Jerry");
	Tom.attack("Micky");
	Tom.attack("Goopy");

	std::cout << std::endl << "\033[1;34m** test 3 : make the scavtrap take damage **\033[0m" << std::endl;
	Tom.takeDamage(2);
	Tom.takeDamage(2);
	Tom.takeDamage(2);

	std::cout << std::endl << "\033[1;34m** test 4 : make the scavtrap get repaired **\033[0m" << std::endl;
	Tom.beRepaired(1);
	Tom.beRepaired(1);

	std::cout << std::endl << "\033[1;34m** test 5 : make the scavtrap activate its special function **\033[0m" << std::endl;
	Tom.guardGate();


	std::cout << std::endl << "\033[1;34m** test 6 : Destructor called with return **\033[0m" << std::endl;

	return (0);
}