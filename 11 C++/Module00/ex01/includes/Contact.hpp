/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:35:49 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/18 17:52:34 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "main.hpp"

class Contact {

	public: 
		Contact(void);
		~Contact(void);

		void		setAttribute(int i, std::string n);
		std::string	getAttribute(int i);

	private:
		std::string	firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNb;
		std::string darkestSecret;

};