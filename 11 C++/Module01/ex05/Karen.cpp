/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 18:44:00 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/27 16:13:56 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen(void) {
	return ;
}

Karen::~Karen(void) {
	return ;
}

void Karen::complain(std::string level) {
	switch (level)
	{
		case "DEBUG":
		case ""
	}
}

void Karen::debug(void) {
	std::cout << "I'm debugging, bitch." << std::endl;
}

void Karen::info(void) {
	std::cout << "I'm your CEO, bitch." << std::endl;
}

void Karen::warning(void) {
	std::cout << "You little slut" << std::endl;
}

void Karen::error(void) {
	std::cout << "You're fired." << std::endl;
}
