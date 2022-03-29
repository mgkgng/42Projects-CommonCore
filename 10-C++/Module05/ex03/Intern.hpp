/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:46:23 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/29 20:19:22 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern();
		Intern(Intern const &);
		~Intern();

		Intern& operator=(Intern const &);

		Form*	makeForm(std::string fName, std::string target);

	private:
		Form*	makeShruberry(std::string target) const;
		Form*	makeRobotomy(std::string target) const;
		Form*	makePresident(std::string taget) const;
};