/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:35:49 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/18 12:36:12 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "main.hpp"

class Contact {

	public: 
		std::string	firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNb;
		std::string darkestSecret;

		Contact(void) ;
		~Contact(void);
};