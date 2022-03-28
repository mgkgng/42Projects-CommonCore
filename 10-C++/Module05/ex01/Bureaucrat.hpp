/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 23:42:33 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/28 23:07:39 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

class Form;

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
		void				signForm(Form& form);

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw() {
					return ("ERROR-BUREAUCRAT: GRADE TOO HIGH");
				}
		};
		
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw() {
					return ("ERROR-BUREAUCRAT: GRADE TOO LOW");
				}
		};
};

std::ostream& operator<<(std::ostream& out, Bureaucrat const &);
