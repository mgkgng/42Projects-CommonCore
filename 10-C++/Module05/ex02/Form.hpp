/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 01:51:30 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/29 01:59:04 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Form {
	
	private:
		std::string const _name;
		bool _signed;
		unsigned int const _signGrade;
		unsigned int const _executeGrade;
		
	public:
		Form();
		Form(std::string name);
		Form(Form const &);
		virtual ~Form();

		Form& operator=(Form const &);

		void	beSigned(Bureaucrat const &);
		virtual void execute(Bureaucrat const & executor) const = 0;

		std::string	const	getName();
		bool				getSigned();
		unsigned int const	getSignGrade();
		unsigned int const	getExecuteGrade();

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