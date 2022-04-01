/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:30:14 by min-kang          #+#    #+#             */
/*   Updated: 2022/04/01 02:21:30 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>

template <typename T>
void	iter(T *array, size_t size, void (*f)(T)) {
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}