/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:32:10 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/18 21:05:12 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contact::Contact(void) {
	return;
}

Contact::~Contact(void) {
	return ;
}

void	Contact::setAttribute(int i, std::string n) {
	switch (i) {
		case 0 :
			this->_firstName = n;
		case 1 :
			this->_lastName = n;
		case 2 :
			this->_nickName = n;
		case 3 :
			this->_phoneNb = n;
		case 4 :
			this->_darkestSecret = n;
	}
}

std::string	Contact::getAttribute(int i) {
	switch (i) {
		case 0 :
			return (this->_firstName);
		case 1 :
			return (this->_lastName);
		case 2 :
			return (this->_nickName);
		case 3 :
			return (this->_phoneNb);
		case 4 :
			return (this->_darkestSecret);
		default :
			return (NULL);
	}
}