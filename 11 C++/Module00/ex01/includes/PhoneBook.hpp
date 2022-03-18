/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:53:54 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/18 12:35:26 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "main.hpp"

class   PhoneBook {
	
	public:
		Contact	contact[8];
		int		size;
	
		PhoneBook(void);
		~PhoneBook(void);
		
		void    saveContact(void);
		void    showContact(void);
		void    showInfo(void);

	private:
		int			_updateContact(void);
		std::string tabSize(std::string s);

};
