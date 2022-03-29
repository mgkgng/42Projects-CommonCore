/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 01:57:26 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/29 19:39:01 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Form.hpp"

class RobotomyRequestForm : public Form {

	private:
		std::string const _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string name);
		RobotomyRequestForm(RobotomyRequestForm const &);
		~RobotomyRequestForm();

		RobotomyRequestForm& operator=(RobotomyRequestForm const &);
		
		void execute(Bureaucrat const & executor) const;
		
		std::string const getTarget() const;

		class NotSignedException : public std::exception {
			public:
				const char *what() const throw() {
					return ("ERROR: NOT SIGNED");
				}
		};

};