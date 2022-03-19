/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:32:07 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/19 19:14:43 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int	main() {

	std::cout << std::endl << "\033[1;34m** test 1 : Human A **\033[0m" << std::endl;
	Weapon club1 = Weapon("crude spiked club");
	HumanA romeo("Romeo", club1);
	romeo.attack();
	club1.setType("some other type of club");
	romeo.attack();

	std::cout << std::endl << "\033[1;34m** test 2 : Human B trying to attack without setting weapon **\033[0m" << std::endl;
	Weapon club2 = Weapon("crude spiked club");
	HumanB juliette("Juliette");
	juliette.attack();
	
	std::cout << std::endl << "\033[1;34m** test 3 : Human B trying to attack after setting weapon **\033[0m" << std::endl;
	juliette.setWeapon(club2);
	juliette.attack();
	club2.setType("some other type of club");
	juliette.attack();

	std::cout << std::endl;

	return (0);
}