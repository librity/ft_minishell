/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/21 13:41:59 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

void	setup(void)
{
	mock_initialize_shell();
}
void	teardown(void)
{
	cleanup_shell();
}

MU_TEST(trivial_tst)
{
	mu_check(true == export((char *[]){"export", "a=10", "b=20", NULL}));
	mu_assert_string_eq(envht_get("a"), "10");
	mu_assert_string_eq(envht_get("b"), "20");

	mu_check(true == export((char *[]){"export", "fire=walk", "with=me", NULL}));
	mu_assert_string_eq(envht_get("fire"), "walk");
	mu_assert_string_eq(envht_get("with"), "me");
}

MU_TEST(no_value_tst)
{
	mu_check(true == export((char *[]){"export", "idade=", NULL}));
	mu_check(NULL == envht_get("idade"));

	mu_check(true == export((char *[]){"export", "with=walk", "idade=", "fire=me", NULL}));
	mu_assert_string_eq(envht_get("with"), "walk");
	mu_check(NULL == envht_get("idade"));
	mu_assert_string_eq(envht_get("fire"), "me");
}

MU_TEST(no_key_tst)
{
	mu_check(false == export((char *[]){"export", "=idade", NULL}));
	mu_check(NULL == envht_get("idade"));

	mu_check(false == export((char *[]){"export", "with=walk", "=idade", "fire=me", NULL}));
	mu_assert_string_eq(envht_get("with"), "walk");
	mu_check(NULL == envht_get("idade"));
	mu_assert_string_eq(envht_get("fire"), "me");
}

MU_TEST_SUITE(export_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(trivial_tst);

	MU_RUN_TEST(no_value_tst);
	MU_RUN_TEST(no_key_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(export_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
