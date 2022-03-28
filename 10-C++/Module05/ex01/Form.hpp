/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 23:42:58 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/28 20:07:13 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat"

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
		~Form();

		Form& operator=(Form const &);

		void beSigned(Bureaucrat const &);
		void signForm();

		void	getName();
		void	getSigned();
		void	getSignGrade();
		void	getExecuteGrade();

	class GradeTooHighException : public std::exception {
		
	};

	class GradeTooLowException : public std::exception {
		
	};
};

std::ostream& operator<<(std::ostream& out, Form const &);