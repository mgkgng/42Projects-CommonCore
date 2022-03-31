/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:08:53 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/31 14:28:18 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

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
			this->setRaw(arg);
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

float	Scalar::getRaw() const {
	return (this->_raw);
}

void	Scalar::setRaw(std::string arg) {
	this->_double_raw = 0;
	if (this->_type == "char")
		this->_raw = static_cast<float>(arg.at(0));
	else if (this->_type == "int")
		this->_raw = static_cast<float>(std::stoi(arg));
	else if (this->_type == "float")
		this->_raw = std::stof(arg);
	else {
		this->_raw = static_cast<float>(std::stod(arg));
		this->_double_raw = std::stod(arg);
	}
}

bool	Scalar::is_displayable(std::string s) {
	for (size_t i = 0; i < s.length(); i++)
		if (!isprint(s.at(i)))
			return (false);
	return (true);
}

bool	Scalar::is_char(std::string s) {
	return (s.length() == 1 && !isdigit(s.at(0))) ? true : false;
}

bool	Scalar::is_int(std::string s) {
	if (s == "inff" || s == "-inff" || s == "nanf" || s == "+inff")
		return (true);

	size_t i = (s.at(0) == '-') ? 1 : 0;

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
	if (s == "inf" || s == "-inf" || s == "nan" || s == "+inf")
		return (true);

	size_t i = (s.at(0) == '-') ? 1 : 0;
	
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
	size_t i = (s.at(0) == '-') ? 1 : 0;
	
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

char	Scalar::to_char() const {
	if (isnan(this->_raw) || isinf(this->_raw) || this->_raw < -128 || this->_raw > 127)
		throw Scalar::Impossible();
	
	if (!isprint(static_cast<int>(this->_raw)))
		throw Scalar::NotDisplayable();

	return (static_cast<char>(this->_raw));
}

int		Scalar::to_int() const {
	if (isnan(this->_raw) || (isinf(this->_raw)) || this->_raw > INT32_MAX || this->_raw < INT32_MIN)
		throw Scalar::Impossible();	
	
	return (static_cast<int>(this->_raw));
}

double	Scalar::to_double() const {
	return ((this->_double_raw) ? this->_double_raw : static_cast<double>(this->_raw));
}

std::ostream& operator<<(std::ostream& out, Scalar const & scalar) {
	std::string type[4] = {"char", "int", "float", "double"};
	for (int i = 0; i < 4; i++) {
		out << type[i] << ": ";
		switch (i) {
			case 0:
				try {
					char c = scalar.to_char();
					out << "'" << c << "'";
				} catch (std::exception &e) {
					out << e.what();
				}
				break;
			case 1:
				try {
					out << scalar.to_int();
				} catch (std::exception &e) {
					out << e.what();
				}
				break;
			case 2:
				float f;
				f = scalar.getRaw();
				out << f;
				if (f - static_cast<int>(f) == 0 && f < 1000000 && f > -1000000)
					out << ".0";
				out << "f";
				break;
			case 3:
				double d = scalar.to_double();
				out << d;
				if (d - static_cast<int>(d) == 0 && d < 1000000 && d > -1000000)
					out << ".0";
				break;
		}
		out << std::endl;
	}
	return (out);
}
