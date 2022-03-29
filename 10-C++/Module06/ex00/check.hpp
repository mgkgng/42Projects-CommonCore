/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:45:07 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/29 23:46:21 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

bool	check_displayable(std::string s);
bool	is_char(std::string s);
bool	is_int(std::string s);
bool	is_float(std::string s);
bool	is_double(std::string s);