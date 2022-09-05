/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_insert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/09/04 19:52:27 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table.h"

bool			_bool;
t_ht_item		*_item;

static void	setup(void)
{
}
static void	teardown(void)
{
}

MU_TEST(insert_one_tst)
{
	g_table = ht_new();
	_bool = ht_insert(g_table, "chave", "value");
	mu_check(_bool == true);

	mu_check(g_table->count == 1);
	g_index = ht_get_index("chave");
	_item = g_table->index_lists[g_index]->content;
	test_ht_item(_item, "chave", "value");

	ht_destroy(&g_table);
}

MU_TEST(insert_two_tst)
{
	g_table = ht_new();
	ht_insert(g_table, "mario", "luigi");
	mu_check(g_table->count == 1);
	ht_insert(g_table, "mamma", "mia");
	mu_check(g_table->count == 2);

	g_index = ht_get_index("mario");
	_item = g_table->index_lists[g_index]->content;
	test_ht_item(_item, "mario", "luigi");

	g_index = ht_get_index("mamma");
	_item = g_table->index_lists[g_index]->content;
	test_ht_item(_item, "mamma", "mia");

	ht_destroy(&g_table);
}

MU_TEST(reinsertion_tst)
{
	g_table = ht_new();
	ht_insert(g_table, "chave", "a");
	ht_insert(g_table, "chave", "b");

	mu_check(g_table->count == 1);
	g_index = ht_get_index("chave");
	_item = g_table->index_lists[g_index]->content;
	test_ht_item(_item, "chave", "b");

	ht_destroy(&g_table);
}

MU_TEST(collision_tst)
{
	g_table = ht_new();
	seed_ht_fixed_index();

	_item = g_table->index_lists[g_index]->content;
	test_ht_item(_item, "buzz", "crash");

	_item = g_table->index_lists[g_index]->next->content;
	test_ht_item(_item, "baz", "fizz");

	_item = g_table->index_lists[g_index]->next->next->content;
	test_ht_item(_item, "foo", "bar");

	ht_destroy(&g_table);
}

MU_TEST(collision_reinsertion_tst)
{
	g_table = ht_new();
	seed_ht_fixed_index();

	ht_insert_in_index(g_table, "baz", "crash", g_index);
	mu_check(g_table->count == 3);

	_item = g_table->index_lists[g_index]->next->content;
	test_ht_item(_item, "baz", "crash");

	ht_destroy(&g_table);
}

MU_TEST(insert_empty_tst)
{
	g_table = ht_new();

	ht_insert(g_table, "", "value");
	mu_check(g_table->count == 1);
	g_index = ht_get_index("");
	_item = g_table->index_lists[g_index]->content;
	test_ht_item(_item, "", "value");

	ht_insert(g_table, "chave", "");
	mu_check(g_table->count == 2);
	g_index = ht_get_index("chave");
	_item = g_table->index_lists[g_index]->content;
	test_ht_item(_item, "chave", "");

	ht_destroy(&g_table);
}

MU_TEST(insert_null_tst)
{
	g_table = ht_new();

	_bool = ht_insert(NULL, "key", "value");
	mu_check(_bool == false);

	_bool = ht_insert(g_table, NULL, "value");
	mu_check(_bool == false);
	mu_check(g_table->count == 0);

	_bool = ht_insert(g_table, "chave", NULL);
	mu_check(_bool == false);
	mu_check(g_table->count == 0);

	ht_destroy(&g_table);
}

MU_TEST_SUITE(hash_table_insert_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(insert_one_tst);
	MU_RUN_TEST(insert_two_tst);
	MU_RUN_TEST(reinsertion_tst);
	MU_RUN_TEST(collision_tst);
	MU_RUN_TEST(collision_reinsertion_tst);
	MU_RUN_TEST(insert_empty_tst);
	MU_RUN_TEST(insert_null_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(hash_table_insert_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
