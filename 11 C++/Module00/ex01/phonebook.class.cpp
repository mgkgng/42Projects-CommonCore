/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:03:55 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/24 15:22:23 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

Phonebook::Phonebook(void)
{
	return ;
}

Phonebook::~Phonebook(void)
{
	return ;
}

void    Phonebook::_updateContact(void){
	int i, j;

	for (i = 0; i < 7; i++)
		for (j = 0; j < 5; j++)
			this->contact[i][j] = this->contact[i + 1][j];
	for (i = 0; i < 5; i++)
		this->contact[7][i].clear();
}

int     Phonebook::_contactSize(void){
	int i = 0;

	while (!this->contact[i][0].empty() && i < 8)
		i++;
	return (i);
}

void    Phonebook::saveContact(void){
	int i;

	i = this->_emptyTab();
	if (i == -1) {
		this->_updateContact();
		i = 7;
	}
	std::cout << "First name : ";
	std::cin >> this->contact[i][0];
	std::cout << "Last name : ";
	std::cin >> this->contact[i][1];    
	std::cout << "Nickname : ";
	std::cin >> this->contact[i][2];    
	std::cout << "Phone number : ";
	std::cin >> this->contact[i][3];    
	std::cout << "The darkest secret : ";
	std::cin >> this->contact[i][4];
}

std::string Phonebook::tabSize(std::string s){
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

void    Phonebook::showContact(void){
	int i, j;
	
	std::cout << "     Index| FirstName|  LastName|  Nickname|" << std::endl;
	//cout << "__________|__________|__________|__________|" << endl;
	for (i = 0; !this->contact[i][0].empty() && i < 8; i++){
		std::cout << "         " << i << "|";
		for (j = 0; j < 3; j++)
			std::cout << this->tabSize(this->contact[i][j]) << "|";
		std::cout << std::endl;
		//cout << endl << "__________|__________|__________|__________|" << endl;
	}
}

void    Phonebook::showInfo(void)
{
	std::string  input;
	int     i;

	while (1) {
		std::cout << "TYPE THE INDEX TO SEE FURTHER INFORMATION : ";
		std::cin >> input;
		if (input.size() == 1 && isdigit(input[0]) 
		&& stoi(input) >= 0 && stoi(input) < _contactSize())
		{
			std::cout << std::endl << "***" << this->contact[stoi(input)][0] << "'s Personal Information ***" << std::endl;
			std::cout << "First Name : " << this->contact[stoi(input)][0] << std::endl;
			std::cout << "Last Name : " << this->contact[stoi(input)][1] << std::endl;
			std::cout << "Nickname : " << this->contact[stoi(input)][2] << std::endl;
			std::cout << "Phone Number : " << this->contact[stoi(input)][3] << std::endl;
			std::cout << "Darkest secret : " << this->contact[stoi(input)][4] << std::endl << std::endl;
		}
		else
			std::cout << std::endl << "***INVALID INDEX***" << std::endl << std::endl;
		std::cout << "TYPE 'EXIT' IN ORDER TO QUIT :";
		std::cin >> input;
		if (!input.compare("EXIT"))
			break;
	}
}

int     Phonebook::_emptyTab(void){
	int i;

	for (i = 0; i < 8; i++)
		if (this->contact[i][0].empty())
			return i;
	return -1;
}

