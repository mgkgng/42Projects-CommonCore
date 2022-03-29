/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 23:42:58 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/29 14:25:28 by min-kang         ###   ########.fr       */
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
		Form(std::string name, unsigned int sg, unsigned int eg);
		Form(Form const &);
		~Form();

		Form& operator=(Form const &);

		void	beSigned(Bureaucrat const &);

		std::string	const	getName() const;
		bool				getSigned() const;
		unsigned int const	getSignGrade() const;
		unsigned int const	getExecuteGrade() const;

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