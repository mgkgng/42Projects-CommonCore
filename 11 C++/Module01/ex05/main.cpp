/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:13:46 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/20 14:07:17 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main(void) {
	Karen k;
	
	std::cout << std::endl << "\033[1;34m** test 1 : Karen Debug **\033[0m" << std::endl;
	k.complain("DEBUG");

	std::cout << std::endl << "\033[1;34m** test 2 : Karen Info **\033[0m" << std::endl;
	k.complain("INFO");

	std::cout << std::endl << "\033[1;34m** test 3 : Karen Warning **\033[0m" << std::endl;
	k.complain("WARNING");

	std::cout << std::endl << "\033[1;34m** test 4 : Karen Error **\033[0m" << std::endl;
	k.complain("ERROR");

	std::cout << std::endl << "\033[1;34m** test 5 : Karen toto **\033[0m" << std::endl;
	k.complain("toto");
	return (0);
}