/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeIdentify.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:38:21 by min-kang          #+#    #+#             */
/*   Updated: 2022/03/30 21:38:59 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <ctime>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);