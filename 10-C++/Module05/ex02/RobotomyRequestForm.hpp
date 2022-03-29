/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 01:57:26 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/29 18:30:08 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
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
};