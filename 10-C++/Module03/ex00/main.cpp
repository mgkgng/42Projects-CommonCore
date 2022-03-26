/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:15:57 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/26 22:58:22 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {

	std::cout << std::endl << "\033[1;34m** test 1 : Creating a claptrap object **\033[0m" << std::endl;
	ClapTrap Tom("Tom");

	std::cout << std::endl << "\033[1;34m** test 2 : make the claptrap object attack **\033[0m" << std::endl;
	Tom.attack("Jerry");
	Tom.attack("Micky");
	Tom.attack("Goopy");

	std::cout << std::endl << "\033[1;34m** test 3 : make the claptrap take damage **\033[0m" << std::endl;
	Tom.takeDamage(2);
	Tom.takeDamage(2);
	Tom.takeDamage(2);

	std::cout << std::endl << "\033[1;34m** test 4 : make the claptrap get repaired **\033[0m" << std::endl;
	Tom.beRepaired(1);
	Tom.beRepaired(1);

	std::cout << std::endl << "\033[1;34m** test 5 : Destructor called with return **\033[0m" << std::endl;

	return (0);
}