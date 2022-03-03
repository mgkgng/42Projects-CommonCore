/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:04:00 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/24 15:10:41 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#include <string>
#include <iostream>

class   Phonebook{
	
	public:
		std::string    contact[8][5];
		Phonebook(void);
		~Phonebook(void);
		void    saveContact(void);
		void    showContact(void);
		void    showInfo(void);
	std::string tabSize(std::string s);

	private:
		int     _emptyTab(void);
		void    _updateContact(void);
		int     _contactSize(void);

};

#endif