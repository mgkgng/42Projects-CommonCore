/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:14:17 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/30 16:55:47 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>


class Scalar {
	
	private:
		std::string _arg;
		std::string _type;
	public:
		Scalar();
		Scalar(std::string arg);
		Scalar(Scalar const &);
		~Scalar();

		Scalar& operator=(Scalar const &);

		bool	is_displayable(std::string arg);
		bool	is_char(std::string arg);
		bool	is_int(std::string arg);
		bool	is_float(std::string arg);
		bool	is_double(std::string arg);

		void	to_char();
		void	to_int();
		void	to_float();
		void	to_double();

		std::string getArg() const;

		class NotDisplayable : public std::exception {
			public:
				const char *what() const throw() {
					return ("Error: Non displayable character found.");
				}
		};
		
		class TypeNotFound : public std::exception {
			public:
				const char *what() const throw() {
					return ("Error: type does not match.");
				}
		}
};