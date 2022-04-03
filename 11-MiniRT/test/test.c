/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilipp <gphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:35:46 by gphilipp          #+#    #+#             */
/*   Updated: 2021/12/14 09:23:47 by gphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minunit.h"

MU_TEST(allowed_function) {
	mu_check(system("sh ./test/allowed_function.sh") == 0);
}

MU_TEST(test_) {
	
}

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(allowed_function);

	MU_RUN_TEST(test_);
}

int main(void) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
