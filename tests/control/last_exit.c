/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:18:40 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/06 16:09:41 by lpaulo-m         ###   ########.fr       */
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

	destroy_last_exit();
}

MU_TEST(reinitialize_tst)
{
	c()->last_exit = NULL;
	mu_check(true == initialize_last_exit());

	mu_check(false == initialize_last_exit());
	mu_check(false == initialize_last_exit());

	destroy_last_exit();
}

MU_TEST(get_tst)
{
	c()->last_exit = NULL;
	mu_check(NULL == last_exit());

	c()->last_exit = "0";
	mu_assert_string_eq("0", last_exit());

	c()->last_exit = "42";
	mu_assert_string_eq("42", last_exit());

	c()->last_exit = "4242";
	mu_assert_string_eq("4242", last_exit());

	c()->last_exit = NULL;
}

MU_TEST(set_tst)
{
	initialize_last_exit();

	set_last_exit(42);
	mu_assert_string_eq("42", c()->last_exit);

	set_last_exit(4242);
	mu_assert_string_eq("4242", c()->last_exit);

	set_last_exit(0);
	mu_assert_string_eq("0", c()->last_exit);

	destroy_last_exit();
}

MU_TEST(set_negative_tst)
{
	mu_check(true == set_last_exit(42));

	mu_check(false == set_last_exit(-5));
	mu_assert_string_eq("42", c()->last_exit);

	destroy_last_exit();
}

MU_TEST(destroy_tst)
{
	initialize_last_exit();

	destroy_last_exit();
	mu_check(NULL == last_exit());
}

MU_TEST_SUITE(last_exit_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(initialize_tst);
	MU_RUN_TEST(reinitialize_tst);

	MU_RUN_TEST(get_tst);

	MU_RUN_TEST(set_tst);
	MU_RUN_TEST(set_negative_tst);

	MU_RUN_TEST(destroy_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(last_exit_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
