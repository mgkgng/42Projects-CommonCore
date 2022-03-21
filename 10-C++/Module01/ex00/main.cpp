/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:52:43 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/21 16:46:43 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::cout << std::endl << "\033[1;34m** test 1 : normal declaration of the Zombie instance and making it announce itself**\033[0m" << std::endl;
	
	Zombie zomeo("Zomeo");
	zomeo.announce();

	std::cout << std::endl << "\033[1;34m** test 2 : using newZombie function**\033[0m" << std::endl;

	Zombie *zuliette = newZombie("Zuliette");
	zuliette->announce();
	delete zuliette;
	
	std::cout << std::endl << "\033[1;34m** test 3 : using randomChump function**\033[0m" << std::endl;

	randomChump("Zozo");

	std::cout << std::endl << "\033[1;34m** test 4 : destructor activated with return **\033[0m" << std::endl;

	return (0);
}