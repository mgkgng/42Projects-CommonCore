/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:09:50 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/31 13:22:22 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Scalar {
	
	private:
		std::string _arg;
		std::string _type;
		float		_raw;

		bool	is_displayable(std::string arg);
		bool	is_char(std::string arg);
		bool	is_int(std::string arg);
		bool	is_float(std::string arg);
		bool	is_double(std::string arg);

	public:
		Scalar();
		Scalar(std::string arg);
		Scalar(Scalar const &);
		~Scalar();

		Scalar& operator=(Scalar const &);

		std::string	to_char();
		std::string	to_int();
		std::string	to_float();
		std::string	to_double();

		std::string	getStr(int i);
		void	setRaw(std::string arg);

		class NotDisplayable : public std::exception {
			public:
				const char *what() const throw() {
					return ("Non displayable");
				}
		};

		class Impossible : public std::exception {
			public:
				const char *what() const throw() {
					return ("Impossible");
				}
		}
		
		class TypeNotFound : public std::exception {
			public:
				const char *what() const throw() {
					return ("Error: type does not match.");
				}
		};
};

std::ostream& operator<<(std::ostream& out, Scalar &);
