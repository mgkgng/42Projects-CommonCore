/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:03:55 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/18 12:19:16 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook(void) : size(0) {
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

int    PhoneBook::_updateContact(void){

	int i = -1;
	while (++i < 7)
		this->contact[i] = this->contact[i + 1];
	return (7);
}

void    PhoneBook::saveContact(void){
	
	int i = (this->size < 8) ? this->size : this->_updateContact();

	std::cout << "First name : ";
	std::cin >> this->contact[i].firstName;
	std::cout << "Last name : ";
	std::cin >> this->contact[i].lastName;    
	std::cout << "Nickname : ";
	std::cin >> this->contact[i].nickName;    
	std::cout << "Phone number : ";
	std::cin >> this->contact[i].phoneNb;    
	std::cout << "The darkest secret : ";
	std::cin >> this->contact[i].darkestSecret;

	if (this->size < 8)
		this->size++;
}

std::string PhoneBook::tabSize(std::string s){

	std::string  result = s;

	if (result.length() <= 10)
		result.insert(0, 10 - result.length(), ' ');
	else {
		while(result.length() != 9)
			result.pop_back();
		result.append(".");
	}
	return result;
}

void    PhoneBook::showContact(void){
	
	std::cout << std::endl;

	if (!this->size) {
		std::cout << "** Phonebook has no registered contact yet **" << std::endl << std::endl;
		return ;
	}
	
	std::cout << "|     Index| FirstName|  LastName|  Nickname|" << std::endl << "|";
	int i = -1;
	while (++i < this->size) {
		std::cout << "         " << i << "|";
		std::cout << this->tabSize(this->contact[i].firstName) << "|";
		std::cout << this->tabSize(this->contact[i].lastName) << "|";
		std::cout << this->tabSize(this->contact[i].nickName) << "|";
		std::cout << std::endl;
		if (i < this->size - 1)
			std::cout << "|";
	}
	std::cout << std::endl;
}

void    PhoneBook::showInfo(void)
{
	std::string  input;
	int     i;

	while (1) {
		std::cout << "TYPE THE INDEX TO SEE FURTHER INFORMATION (TYPE 'QUIT' TO BREAK): ";
		std::cin >> input;
		if (input.size() == 1 && isdigit(input[0]) 
		&& stoi(input) >= 0 && stoi(input) < this->size)
		{
			std::cout << std::endl << "***" << this->contact[stoi(input)].firstName << "'s Personal Information ***" << std::endl;
			std::cout << "First Name : " << this->contact[stoi(input)].firstName << std::endl;
			std::cout << "Last Name : " << this->contact[stoi(input)].lastName << std::endl;
			std::cout << "Nickname : " << this->contact[stoi(input)].nickName << std::endl;
			std::cout << "Phone Number : " << this->contact[stoi(input)].phoneNb << std::endl;
			std::cout << "Darkest secret : " << this->contact[stoi(input)].darkestSecret << std::endl << std::endl;
		}
		else if (!input.compare("QUIT"))
			break;
		else
			std::cout << std::endl << "***INVALID INDEX***" << std::endl << std::endl;
	}
}