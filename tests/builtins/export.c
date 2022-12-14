/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/28 17:24:30 by lpaulo-m         ###   ########.fr       */
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
	mu_check(0 == bi_export((char *[]){"export", "porridge=10", NULL}));
	mu_assert_string_eq(envht_get("porridge"), "10");
	mu_check(NULL == envht_get("oats"));

	mu_check(0 == bi_export((char *[]){"export", "fire=walk", "with=me", NULL}));
	mu_assert_string_eq(envht_get("fire"), "walk");
	mu_assert_string_eq(envht_get("with"), "me");
}

MU_TEST(no_value_tst)
{
	mu_check(0 == bi_export((char *[]){"export", "laura=", NULL}));
	mu_assert_string_eq("", envht_get("laura"));

	mu_check(0 == bi_export((char *[]){"export", "with=walk", "palmer=", "fire=me", NULL}));
	mu_assert_string_eq("walk", envht_get("with"));
	mu_assert_string_eq("", envht_get("palmer"));
	mu_assert_string_eq("me", envht_get("fire"));
}

MU_TEST(no_assignment_tst)
{
	mu_check(0 == bi_export((char *[]){"export", "garmonbozia", NULL}));
	mu_check(NULL == envht_get("garmonbozia"));

	mu_check(0 == bi_export((char *[]){"export", "with=walk", "garmonbozia", "fire=me", NULL}));
	mu_assert_string_eq(envht_get("with"), "walk");
	mu_check(NULL == envht_get("idade"));
	mu_assert_string_eq(envht_get("fire"), "me");
}

MU_TEST(no_key_tst)
{
	mu_check(1 == bi_export((char *[]){"export", "=idade", NULL}));
	mu_check(NULL == envht_get("idade"));

	mu_check(1 == bi_export((char *[]){"export", "with=walk", "=idade", "fire=me", NULL}));
	mu_assert_string_eq(envht_get("with"), "walk");
	mu_check(NULL == envht_get("idade"));
	mu_assert_string_eq(envht_get("fire"), "me");
}

MU_TEST(empty_tst)
{
	mu_check(1 == bi_export((char *[]){"export", "=", NULL}));
	mu_check(1 == bi_export((char *[]){"export", "", NULL}));
}

MU_TEST(number_name_tst)
{
	mu_check(1 == bi_export((char *[]){"export", "1teste=idade", NULL}));
	mu_check(NULL == envht_get("1teste"));

	mu_check(1 == bi_export((char *[]){"export", "with=walk", "2teste=idade", "fire=me", NULL}));
	mu_assert_string_eq(envht_get("with"), "walk");
	mu_check(NULL == envht_get("2teste"));
	mu_assert_string_eq(envht_get("fire"), "me");
}

MU_TEST(meta_name_tst)
{
	mu_check(0 == bi_export((char *[]){"export", "test=e=idade", NULL}));
	mu_assert_string_eq(envht_get("test"), "e=idade");

	mu_check(1 == bi_export((char *[]){"export", "test?e=idade", NULL}));
	mu_check(NULL == envht_get("test?e"));

	mu_check(1 == bi_export((char *[]){"export", "with=walk", "2te\'ste=idade", "fire=me", NULL}));
	mu_assert_string_eq(envht_get("with"), "walk");
	mu_check(NULL == envht_get("2te\'ste"));
	mu_assert_string_eq(envht_get("fire"), "me");

	mu_check(1 == bi_export((char *[]){"export", "test\"e=idade", NULL}));
	mu_check(NULL == envht_get("test\"e"));

	mu_check(1 == bi_export((char *[]){"export", "test\\e=idade", NULL}));
	mu_check(NULL == envht_get("test\\e"));

	mu_check(1 == bi_export((char *[]){"export", "test$e=idade", NULL}));
	mu_check(NULL == envht_get("test$e"));

	mu_check(1 == bi_export((char *[]){"export", "test`e=idade", NULL}));
	mu_check(NULL == envht_get("test`e"));

	mu_check(1 == bi_export((char *[]){"export", "tes*te=idade", NULL}));
	mu_check(NULL == envht_get("tes*t"));

	mu_check(1 == bi_export((char *[]){"export", "tes@te=idade", NULL}));
	mu_check(NULL == envht_get("tes@t"));

	mu_check(1 == bi_export((char *[]){"export", "tes~te=idade", NULL}));
	mu_check(NULL == envht_get("tes~t"));

	mu_check(1 == bi_export((char *[]){"export", "tes<te=idade", NULL}));
	mu_check(NULL == envht_get("tes<t"));

	mu_check(1 == bi_export((char *[]){"export", "tes>te=idade", NULL}));
	mu_check(NULL == envht_get("tes>t"));

	mu_check(1 == bi_export((char *[]){"export", "tes(te=idade", NULL}));
	mu_check(NULL == envht_get("tes(t"));

	mu_check(1 == bi_export((char *[]){"export", "tes)te=idade", NULL}));
	mu_check(NULL == envht_get("tes)t"));

	mu_check(1 == bi_export((char *[]){"export", "tes!te=idade", NULL}));
	mu_check(NULL == envht_get("tes!t"));

	mu_check(1 == bi_export((char *[]){"export", "tes!te=idade", NULL}));
	mu_check(NULL == envht_get("tes!t"));

	mu_check(1 == bi_export((char *[]){"export", "tes|te=idade", NULL}));
	mu_check(NULL == envht_get("tes|t"));

	mu_check(1 == bi_export((char *[]){"export", "tes&te=idade", NULL}));
	mu_check(NULL == envht_get("tes&t"));

	mu_check(1 == bi_export((char *[]){"export", "tes;te=idade", NULL}));
	mu_check(NULL == envht_get("tes;t"));

	mu_check(1 == bi_export((char *[]){"export", "tes te=idade", NULL}));
	mu_check(NULL == envht_get("tes t"));

	mu_check(1 == bi_export((char *[]){"export", "tes\nte=idade", NULL}));
	mu_check(NULL == envht_get("tes\nt"));
}


MU_TEST(dump_tst)
{
	mu_check(0 == bi_export((char *[]){"export", NULL}));
}

MU_TEST_SUITE(export_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(trivial_tst);

	MU_RUN_TEST(no_value_tst);
	MU_RUN_TEST(no_assignment_tst);

	MU_RUN_TEST(no_key_tst);
	MU_RUN_TEST(empty_tst);

	MU_RUN_TEST(number_name_tst);
	MU_RUN_TEST(meta_name_tst);

	MU_RUN_TEST(dump_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(export_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
