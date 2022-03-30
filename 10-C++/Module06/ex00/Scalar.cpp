/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:38:43 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/30 19:40:21 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

std::string special[6] = {"inf", "-inf", "nan", "inff", "-inff", "nanf"};

Scalar::Scalar() {
	std::cout << "Scalar default constrcutor called." << std::endl;
}

Scalar::Scalar(std::string arg) : _arg(arg) {
	std::cout << "Scalar string constructor called." << std::endl;

	if (!this->is_displayable(arg))
		throw Scalar::NotDisplayable();

	bool (Scalar::*func[4])(std::string) = {&Scalar::is_char, &Scalar::is_int, &Scalar::is_float, &Scalar::is_double};
	std::string type[4] = {"char", "int", "float", "double"};
	for (int i = 0; i < 4; i++) {
		if ((this->*func[i])(arg)) {
			this->_type = type[i];
			return ;
		}
	}
	throw Scalar::TypeNotFound();
}

Scalar::Scalar(Scalar const & src) {
	std::cout << "Scalar copy constructor called." << std::endl;
	*this = src;
}

Scalar::~Scalar() {
	std::cout << "Scalar destructor called." << std::endl;
}

Scalar& Scalar::operator=(Scalar const & right) {
	this->_arg = right._arg;
	this->_type = right._type;
	return (*this);
}

std::string Scalar::getArg() const {
	return (this->_arg);
}

bool	Scalar::is_displayable(std::string s) {
	for (int i = 0; i < s.length(); i++)
		if (!isprint(s.at(i)))
			return (false);
	return (true);
}

bool	Scalar::is_char(std::string s) {
	return (s.length() == 1 && !isdigit(s.at(0))) ? true : false;
}

bool	Scalar::is_int(std::string s) {
	if (s == "inff" || s == "-inff" || s == "nanf")
		return (true);

	int i = (s.at(0) == '-') ? 1 : 0;

	while (i < s.length())
		if (!isdigit(s.at(i++)))
			return (false);
	try {
		std::stoi(s);
	} catch (std::out_of_range &e) {
		return (false);
	}
	return (true);
}

bool	Scalar::is_float(std::string s) {
	if (s == "inf" || s == "-inf" || s == "nan")
		return (true);

	int i = (s.at(0) == '-') ? 1 : 0;
	
	if (s.at(s.length() - 1) != 'f' || s.find('.') == std::string::npos)
		return (false);
	while (i < s.length() && s.at(i) != '.')
		if (!isdigit(s.at(i++)))
			return (false);
	while (++i < s.length() - 1)
		if (!isdigit(s.at(i)))
			return (false);
	try {
		std::stof(s);
	} catch (std::out_of_range &e) {
		return (false);
	}
	return (true);
}

bool	Scalar::is_double(std::string s) {
	int i = (s.at(0) == '-') ? 1 : 0;
	
	if (s.find('.') == std::string::npos)
		return (false);
	while (i < s.length() && s.at(i) != '.')
		if (!isdigit(s.at(i++)))
			return (false);
	while (++i < s.length())
		if (!isdigit(s.at(i)))
			return (false);
	try {
		std::stod(s);
	} catch (std::out_of_range &e) {
		return (false);
	}
	return (true);
}

std::string	Scalar::to_char() {

	for (int i = 0; i < 6; i++)
		if (this->_arg == special[i])
			return ("impossible");
	
	try {
		char c = static_cast<char>(std::stoi(this->_arg));
		return (isprint(c)) ? "'" + std::to_string(c) + "'" : "Non displayable";
	} catch (std::bad_cast &bc) {
		std::cout << "Error, bad cast" << std::endl;
	}
}

std::string	Scalar::to_int() {
	for (int i = 0; i < 6; i++)
		if (this->_arg == special[i])
			return ("impossible");

	try {
		return (std::to_string(std::stoi(this->_arg)));
	} catch (std::bad_cast &bc) {
		std::cout << "Error, bad cast" << std::endl;
	}

}

std::string	Scalar::to_float() {
	try {
		return (std::to_string(std::stof(this->_arg)));
	} catch (std::bad_cast &bc) {
		std::cout << "Error, bad cast" << std::endl;
	}
}

std::string	Scalar::to_double() {
	try {
		return (std::to_string(std::stod(this->_arg)));
	} catch (std::bad_cast &bc) {
		std::cout << "Error, bad cast" << std::endl;
	}
}

std::string Scalar::getStr(int i) const {
	std::string (Scalar::*func[4])() = {&Scalar::to_char, &Scalar::to_int, &Scalar::to_float, &Scalar::to_double};
	return (this->*func[i])();
}

std::ostream& operator<<(std::ostream& out, Scalar const & scalar) {
	std::string	type[4] = {"char", "int", "float", "double"};
	for (int i = 0; i < 4; i++)
		std::cout << type[i] << ": " << scalar.getStr(i) << std::endl;
}