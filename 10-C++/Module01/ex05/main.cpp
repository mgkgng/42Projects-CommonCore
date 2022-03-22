/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:13:46 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/22 14:47:13 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void) {

	Harl h;
	
	std::cout << std::endl << "\033[1;34m** test 1 : Harl Debug **\033[0m" << std::endl;
	h.complain("DEBUG");

	std::cout << std::endl << "\033[1;34m** test 2 : Harl Info **\033[0m" << std::endl;
	h.complain("INFO");

	std::cout << std::endl << "\033[1;34m** test 3 : Harl Warning **\033[0m" << std::endl;
	h.complain("WARNING");

	std::cout << std::endl << "\033[1;34m** test 4 : Harl Error **\033[0m" << std::endl;
	h.complain("ERROR");

	std::cout << std::endl << "\033[1;34m** test 5 : Harl toto **\033[0m" << std::endl;
	h.complain("toto");
	return (0);
}