/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotmoyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 01:57:26 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/29 01:57:43 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

class RobotomyRequestForm : public Form {

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &);
		~RobotomyRequestForm();

		RobotomyRequestForm& operator=(RobotomyRequestForm const &);
};