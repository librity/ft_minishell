/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:18:40 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/06 15:35:03 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(initialize_tst)
{
	mu_check(c()->last_exit == NULL);

	initialize_last_exit();
	mu_assert_string_eq("0", c()->last_exit);
}

MU_TEST_SUITE(last_exit_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(initialize_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(last_exit_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
