/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:58:41 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/27 20:01:23 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Bureaucrat {
	
	private:
		std::string const	_name;
		unsigned int		_grade;
	
	public:
		Bureaucrat(void);
		Bureaucrat(unsigned int grade);
		Bureaucrat(Bureaucrat const &);
		~Bureaucrat(void);

		Bureaucrat& operator=(Bureaucrat const &);
};