/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_insert_strarr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/09/04 22:58:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table.h"

t_hash_table	*_table;
char			*_str;
char			**_strarr;
bool			_bool;

static void	setup(void)
{
}
static void	teardown(void)
{
}

MU_TEST(trivial_tst)
{
	_table = ht_new();
	_strarr = (char *[]){
		"foo=bar",
		"fizz=buzz",
		"gar=mon",
		"bo=zia",
		NULL};
	_bool = ht_insert_strarr(_table, _strarr);
	mu_check(true == _bool);

	_str = ht_get(_table, "foo");
	mu_assert_string_eq("bar", _str);

	_str = ht_get(_table, "fizz");
	mu_assert_string_eq("buzz", _str);

	_str = ht_get(_table, "gar");
	mu_assert_string_eq("mon", _str);

	_str = ht_get(_table, "bo");
	mu_assert_string_eq("zia", _str);

	ht_destroy(&_table);
}

MU_TEST(no_equals_tst)
{
	_table = ht_new();
	_strarr = (char *[]){
		"foo=bar",
		"garmon",
		"bo=zia",
		NULL};
	_bool = ht_insert_strarr(_table, _strarr);
	mu_check(false == _bool);

	_str = ht_get(_table, "foo");
	mu_assert_string_eq("bar", _str);

	_str = ht_get(_table, "gar");
	mu_check(NULL == _str);

	_str = ht_get(_table, "bo");
	mu_check(NULL == _str);

	ht_destroy(&_table);
}

MU_TEST(null_tst)
{
	_bool = ht_insert_strarr(NULL, _strarr);
	mu_check(false == _bool);

	_table = ht_new();
	_bool = ht_insert_strarr(_table, NULL);
	mu_check(false == _bool);

	ht_destroy(&_table);
}

MU_TEST_SUITE(insert_strarr_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(trivial_tst);
	MU_RUN_TEST(no_equals_tst);
	MU_RUN_TEST(null_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(insert_strarr_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
