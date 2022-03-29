/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 01:56:52 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/29 01:56:54 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

class ShrubberyCreationForm : public Form {

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &);
		~ShrubberyCreationForm();

		ShrubberyCreationForm& operator=(ShrubberyCreationForm const &);
};