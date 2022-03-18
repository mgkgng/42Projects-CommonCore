/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:53:54 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/18 20:33:45 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "main.hpp"

class   PhoneBook {
	
	public:

		PhoneBook(void);
		~PhoneBook(void);
		
		void    saveContact(void);
		void    showContact(void);
		void    showInfo(void);

	private:
		Contact	contact[8];
		int		_size;

		int			_updateContact(void);
		std::string tabSize(std::string s);

};
