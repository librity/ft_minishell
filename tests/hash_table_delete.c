/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_delete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/09/04 19:02:56 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table.h"

char			*_str;
bool			_bool;
t_ht_item		*_item;
t_dlist			*_node;

void	setup(void)
{
}
void	teardown(void)
{
}

MU_TEST(delete_tst)
{
	g_table = ht_new();
	seed_ht();

	ht_delete(g_table, "foo");
	mu_check(g_table->count == 2);
	_str = ht_get(g_table, "foo");
	mu_check(_str == NULL);

	ht_delete(g_table, "baz");
	mu_check(g_table->count == 1);
	_str = ht_get(g_table, "baz");
	mu_check(_str == NULL);

	ht_delete(g_table, "buzz");
	mu_check(g_table->count == 0);
	_str = ht_get(g_table, "buzz");
	mu_check(_str == NULL);

	ht_destroy(&g_table);
}

MU_TEST(delete_twice_tst)
{
	g_table = ht_new();
	seed_ht();

	ht_delete(g_table, "baz");
	mu_check(g_table->count == 2);
	_str = ht_get(g_table, "baz");
	mu_check(_str == NULL);

	ht_delete(g_table, "baz");
	mu_check(g_table->count == 2);
	_str = ht_get(g_table, "baz");
	mu_check(_str == NULL);

	ht_destroy(&g_table);
}

MU_TEST(delete_same_index_tst)
{
	g_table = ht_new();
	seed_ht_fixed_index();
	ht_insert_in_index(g_table, "bada", "bing", g_index);
	mu_check(g_table->count == 4);

	{
		ht_delete_in_index(g_table, "foo", g_index);
		mu_check(g_table->count == 3);
		_node = g_table->index_lists[g_index]->next->next->next;
		mu_check(_node == NULL);
		_item = g_table->index_lists[g_index]->next->next->content;
		test_ht_item(_item, "baz", "fizz");
		_item = g_table->index_lists[g_index]->next->content;
		test_ht_item(_item, "buzz", "crash");
		_item = g_table->index_lists[g_index]->content;
		test_ht_item(_item, "bada", "bing");
	}

	{
		ht_delete_in_index(g_table, "buzz", g_index);
		mu_check(g_table->count == 2);
		_node = g_table->index_lists[g_index]->next->next;
		mu_check(_node == NULL);
		_item = g_table->index_lists[g_index]->next->content;
		test_ht_item(_item, "baz", "fizz");
		_item = g_table->index_lists[g_index]->content;
		test_ht_item(_item, "bada", "bing");
	}

	{
		ht_delete_in_index(g_table, "baz", g_index);
		mu_check(g_table->count == 1);
		_node = g_table->index_lists[g_index]->next;
		mu_check(_node == NULL);
		_item = g_table->index_lists[g_index]->content;
		test_ht_item(_item, "bada", "bing");
	}

	{
		ht_delete_in_index(g_table, "bada", g_index);
		mu_check(g_table->count == 0);
		_node = g_table->index_lists[g_index];
		mu_check(_node == NULL);
	}

	{
		ht_delete_in_index(g_table, "bada", g_index);
		mu_check(g_table->count == 0);
		_node = g_table->index_lists[g_index];
		mu_check(_node == NULL);
	}

	ht_destroy(&g_table);
}

MU_TEST(delete_empty_tst)
{
	g_table = ht_new();

	_bool = ht_delete(g_table, "");
	mu_check(_bool == false);

	ht_insert(g_table, "", "_str");
	_bool = ht_delete(g_table, "");
	mu_check(_bool == true);

	_bool = ht_delete(g_table, "");
	mu_check(_bool == false);

	ht_destroy(&g_table);
}

MU_TEST(delete_null_tst)
{
	g_table = ht_new();

	_bool = ht_delete(NULL, "key");
	mu_check(_bool == false);

	_bool = ht_delete(g_table, NULL);
	mu_check(_bool == false);

	ht_destroy(&g_table);
}

MU_TEST_SUITE(hash_table_delete_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(delete_tst);
	MU_RUN_TEST(delete_twice_tst);
	MU_RUN_TEST(delete_same_index_tst);
	MU_RUN_TEST(delete_empty_tst);
	MU_RUN_TEST(delete_null_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(hash_table_delete_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
