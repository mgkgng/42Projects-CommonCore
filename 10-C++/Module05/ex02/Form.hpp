/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 01:51:30 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/29 18:10:20 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Form {
	
	private:
		std::string const _name;
		bool _signed;
		unsigned int _signGrade;
		unsigned int _execGrade;
		
	public:
		Form();
		Form(std::string name, unsigned int sg, unsigned int eg);
		Form(Form const &);
		virtual ~Form();

		Form& operator=(Form const &);
		
		virtual void execute(Bureaucrat const & executor) const = 0;

		void	beSigned(Bureaucrat const &);

		std::string	const	getName() const;
		bool				getSigned() const;
		unsigned int	getSignGrade() const;
		unsigned int	getExecGrade() const;

		void	setName(std::string name);
		void	setSigned(bool sign);
		void	setSignGrade(unsigned int grade);
		void	setExecGrade(unsigned int grade);

	class GradeTooHighException : public std::exception {
		public:
			const char *what() const throw() {
				return ("ERROR-FORM: GRADE TOO HIGH");
			}
	};

	class GradeTooLowException : public std::exception {
		public:
			const char *what() const throw() {
				return ("ERROR-FORM: GRADE TOO LOW");
			}
	};
};

std::ostream& operator<<(std::ostream& out, Form const &);