/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:03:55 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/19 18:43:26 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook(void) : _size(0) {
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
	
	int i = (this->_size < 8) ? this->_size : this->_updateContact();

	std::string s;
	std::cout << "First name : ";
	getline(std::cin, s);
	this->contact[i].setAttribute(0, s);
	std::cout << "Last name : ";
	getline(std::cin, s);
	this->contact[i].setAttribute(1, s);    
	std::cout << "Nickname : ";
	getline(std::cin, s);
	this->contact[i].setAttribute(2, s);    
	std::cout << "Phone number : ";
	getline(std::cin, s);
	this->contact[i].setAttribute(3, s);    
	std::cout << "The darkest secret : ";
	getline(std::cin, s);
	this->contact[i].setAttribute(4, s);

	if (this->_size < 8)
		this->_size++;
}

std::string PhoneBook::tabSize(std::string s) {

	std::string  res = s;

	if (res.length() > 10)
		res = res.substr(0, 8).append(".");
	return (res);
}

void    PhoneBook::showContact(void) {
	
	std::cout << std::endl;

	if (!this->_size) {
		std::cout << "** Phonebook has no registered contact yet **" << std::endl << std::endl;
		return ;
	}
	
	std::cout << "|     Index| FirstName|  LastName|  Nickname|" << std::endl << "|";
	int i = -1;
	while (++i < this->_size) {
		std::cout << std::setfill(' ') << std::setw(10) << i << "|";
		std::cout << std::setfill(' ') << std::setw(10) << this->tabSize(this->contact[i].getAttribute(0)) << "|";
		std::cout << std::setfill(' ') << std::setw(10) << this->tabSize(this->contact[i].getAttribute(1)) << "|";
		std::cout << std::setfill(' ') << std::setw(10) << this->tabSize(this->contact[i].getAttribute(2)) << "|";
		std::cout << std::endl;
		if (i < this->_size - 1)
			std::cout << "|";
	}
	std::cout << std::endl;

	if (this->_size)
		this->showInfo();
}

void    PhoneBook::showInfo(void)
{
	std::string	input;
	int     	i;

	do {
		std::cout << "TYPE THE INDEX TO SEE FURTHER INFORMATION (TYPE 'QUIT' TO BREAK): ";
		getline(std::cin, input);
		if (input != "" && input.size() == 1 && isdigit(input[0]) 
		&& stoi(input) >= 0 && stoi(input) < this->_size)
		{
			std::cout << std::endl << "***" << this->contact[stoi(input)].getAttribute(0) << "'s Personal Information ***" << std::endl;
			std::cout << "First Name : " << this->contact[stoi(input)].getAttribute(0) << std::endl;
			std::cout << "Last Name : " << this->contact[stoi(input)].getAttribute(1) << std::endl;
			std::cout << "Nickname : " << this->contact[stoi(input)].getAttribute(2) << std::endl;
			std::cout << "Phone Number : " << this->contact[stoi(input)].getAttribute(3) << std::endl;
			std::cout << "Darkest secret : " << this->contact[stoi(input)].getAttribute(4) << std::endl << std::endl;
		}
		else if (input != "" && input != "QUIT")
			std::cout << std::endl << "*** INVALID INDEX ***" << std::endl << std::endl;
	} while (input != "QUIT" && !std::cin.eof());
}