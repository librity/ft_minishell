/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_get.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/09/04 19:02:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table.h"

char			*_str;
bool			_bool;

void	setup(void)
{
}
void	teardown(void)
{
}

MU_TEST(get_tst)
{
	g_table = ht_new();
	seed_ht();

	_str = ht_get(g_table, "foo");
	mu_assert_string_eq("bar", _str);

	_str = ht_get(g_table, "baz");
	mu_assert_string_eq("fizz", _str);

	_str = ht_get(g_table, "buzz");
	mu_assert_string_eq("crash", _str);

	ht_destroy(&g_table);
}

MU_TEST(get_bad_key_tst)
{
	g_table = ht_new();
	seed_ht();

	_str = ht_get(g_table, "idontexist");
	mu_check(_str == NULL);

	_str = ht_get(g_table, "idontexisteither");
	mu_check(_str == NULL);

	_str = ht_get(g_table, "idontexist");
	mu_check(_str == NULL);

	_str = ht_get(g_table, "are we there yet?");
	mu_check(_str == NULL);

	ht_destroy(&g_table);
}

MU_TEST(get_reinsertion_tst)
{
	g_table = ht_new();
	seed_ht();

	ht_insert(g_table, "baz", "crash");
	_str = ht_get(g_table, "baz");
	mu_assert_string_eq("crash", _str);

	ht_destroy(&g_table);
}

MU_TEST(get_empty_tst)
{
	g_table = ht_new();

	ht_insert(g_table, "", "bar");
	_str = ht_get(g_table, "");
	mu_assert_string_eq("bar", _str);

	ht_insert(g_table, "foo", "");
	_str = ht_get(g_table, "foo");
	mu_assert_string_eq("", _str);

	ht_destroy(&g_table);
}

MU_TEST(get_null_tst)
{
	g_table = ht_new();

	_str = ht_get(NULL, "foo");
	mu_check(_str == NULL);

	_str = ht_get(g_table, NULL);
	mu_check(_str == NULL);

	ht_destroy(&g_table);
}

MU_TEST_SUITE(hash_table_get_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(get_tst);
	MU_RUN_TEST(get_bad_key_tst);
	MU_RUN_TEST(get_reinsertion_tst);
	MU_RUN_TEST(get_empty_tst);
	MU_RUN_TEST(get_null_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(hash_table_get_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
