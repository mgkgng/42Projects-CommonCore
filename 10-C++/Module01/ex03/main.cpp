/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:32:07 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/23 11:50:48 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int	main() {

	std::cout << std::endl << "\033[1;34m** test 1 : Human A **\033[0m" << std::endl;
	Weapon club1 = Weapon("crude spiked club");
	HumanA buendia("Jose Arcadio Buendia", club1);
	buendia.attack();
	club1.setType("some other type of club");
	buendia.attack();

	std::cout << std::endl << "\033[1;34m** test 2 : Human B trying to attack without setting weapon **\033[0m" << std::endl;
	Weapon club2 = Weapon("crude spiked club");
	HumanB melquiades("Melquiades");
	melquiades.attack();
	
	std::cout << std::endl << "\033[1;34m** test 3 : Human B trying to attack after setting weapon **\033[0m" << std::endl;
	melquiades.setWeapon(club2);
	melquiades.attack();
	club2.setType("some other type of club");
	melquiades.attack();

	std::cout << std::endl << "\033[1;34m** test 4 : trying to disarm Human B **\033[0m" << std::endl;
	melquiades.disarm();
	melquiades.attack();

	std::cout << std::endl;

	return (0);
}