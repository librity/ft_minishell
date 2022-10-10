/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/10/10 15:41:47 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table.h"

t_ht_item		*_item;
char			*_str;

static void	setup(void)
{
}
static void	teardown(void)
{
}


MU_TEST(new_item_tst)
{
	_item = ht_new_item("abc", "value");
	test_ht_item(_item, "abc", "value");

	ht_destroy_item(&_item);
}

MU_TEST(new_item_empty_tst)
{
	_item = ht_new_item("", "value");
	test_ht_item(_item, "", "value");
	ht_destroy_item(&_item);

	_item = ht_new_item("abc", "");
	test_ht_item(_item, "abc", "");
	ht_destroy_item(&_item);
}

MU_TEST(new_item_null_tst)
{
	_item = ht_new_item(NULL, "value");
	mu_check(_item == NULL);

	_item = ht_new_item("abc", NULL);
	mu_check(_item == NULL);
}

MU_TEST(destroy_item_tst)
{
	_item = ht_new_item("bananas", "pajamas");
	test_ht_item(_item, "bananas", "pajamas");

	ht_destroy_item(&_item);
	mu_check(_item == NULL);
}

MU_TEST(destroy_item_null_tst)
{
	supress_stdout();

	ht_destroy_item(NULL);

	_item = NULL;
	ht_destroy_item(&_item);

	restore_stdout();
}

MU_TEST(to_string_tst)
{
	_item = ht_new_item("bananas", "pajamas");
	_str = ht_item_to_string(_item);
	mu_assert_string_eq("bananas=pajamas", _str);
	ht_destroy_item(&_item);
	free(_str);

	_item = ht_new_item("gar", "mon");
	_str = ht_item_to_string(_item);
	mu_assert_string_eq("gar=mon", _str);
	ht_destroy_item(&_item);
	free(_str);

	_item = ht_new_item("bo", "zia");
	_str = ht_item_to_string(_item);
	mu_assert_string_eq("bo=zia", _str);
	ht_destroy_item(&_item);
	free(_str);
}

MU_TEST(to_string_null_tst)
{
	_str = ht_item_to_string(NULL);
	mu_check(NULL == _str);
}

MU_TEST_SUITE(hash_table_core_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(new_item_tst);
	MU_RUN_TEST(new_item_empty_tst);
	MU_RUN_TEST(new_item_null_tst);

	MU_RUN_TEST(destroy_item_tst);
	MU_RUN_TEST(destroy_item_null_tst);

	MU_RUN_TEST(to_string_tst);
	MU_RUN_TEST(to_string_null_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(hash_table_core_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
