/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:55:45 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/30 19:57:19 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

struct Data {
	
	private:
		int			wtf;
	
	public:
		Data();
		Data(int);
		Data(Data const &);
		~Data();

		Data& operator=(Data const &);
	
};