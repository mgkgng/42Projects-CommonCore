/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:32:07 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/26 12:50:06 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int	main() {

	std::cout << "--------------Test HumanA--------------" << std::endl;
	Weapon club1 = Weapon("crude spiked club");
	HumanA bob("Bob", club1);
	bob.attack();
	club1.setType("some other type of club");
	bob.attack();

	std::cout << "--------------Test HumanB--------------" << std::endl;
	Weapon club2 = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club2);
	jim.attack();
	club2.setType("some other type of club");
	jim.attack();

	std::cout << "--------------Test Done----------------" << std::endl;


}