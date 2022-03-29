/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 01:58:21 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/29 01:58:22 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

class PresidentialPardonForm : public Form {

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &);
		~PresidentialPardonForm();

		PresidentialPardonForm& operator=(PresidentialPardonForm const &);
};