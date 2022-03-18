/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:14:11 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/18 21:39:26 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << std::endl << "\033[1;34m** test 1 : using zombieHorde function to make a horde of zombies**\033[0m" << std::endl;

	Zombie	*zhorde = zombieHorde(10, "Zomeo");
	zhorde[0].announce();
	zhorde[n - 1].announce();
	delete [] zhorde;

	return (0);
}