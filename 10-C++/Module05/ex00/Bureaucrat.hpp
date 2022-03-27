/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:58:41 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/27 23:19:40 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat {
	
	private:
		std::string const	_name;
		unsigned int		_grade;
	
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(Bureaucrat const &);
		~Bureaucrat(void);

		Bureaucrat& operator=(Bureaucrat const &);

		std::string	const	getName(void) const;
		unsigned int		getGrade(void) const;
		void				UpGrade(void);
		void				DownGrade(void);

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw() {
					return ("ERROR: GRADE TOO HIGH");
				}
		};
		
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw() {
					return ("ERROR: GRADE TOO LOW");
				}
		};
};

std::ostream& operator<<(std::ostream& out, Bureaucrat const &);
