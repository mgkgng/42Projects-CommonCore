/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:24:47 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/30 01:26:49 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

typedef struct {
	int			int_data;
	std::string string_data;
	float		float_data;
	Data*		data_data;
} Data;

uintptr_t	serialize(Data *ptr);
Data*		deserialize(uintptr_t raw);