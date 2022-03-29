/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:54:43 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/29 18:58:05 by min-kang         ###   ########.fr       */
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
		Bureaucrat();
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(Bureaucrat const &);
		~Bureaucrat();

		Bureaucrat& operator=(Bureaucrat const &);

		std::string	const	getName() const;
		unsigned int		getGrade() const;
		void				UpGrade();
		void				DownGrade();

		void				signForm(Form& form);
		void				executeForm(Form const & form);

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