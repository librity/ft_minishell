/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/08/30 17:46:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		_index;
int		expected;

void	setup(void)
{
}
void	teardown(void)
{
}

MU_TEST(ht_index_tst)
{
	_index = ht_get_index("abc");
	expected = (int)(md5_sum("abc") % HASH_TABLE_SIZE);
	mu_assert_int_eq(expected, _index);
}

MU_TEST(ht_init_tst)
{
	t_hash_table	*hash_table;

	hash_table = ht_init();
	mu_check(hash_table != NULL);
	free(hash_table->index_lists);
	free(hash_table);
}

MU_TEST(ht_destroy_tst)
{
	t_hash_table	*hash_table;

	hash_table = ht_init();
	mu_check(hash_table != NULL);
	ht_destroy(&hash_table);
	mu_check(hash_table == NULL);
}

MU_TEST(ht_new_item_tst)
{
	t_ht_item	*item;

	item = ht_new_item("abc", "value");
	mu_check(item != NULL);
	mu_assert_string_eq("abc", item->key);
	mu_assert_string_eq("value", item->value);
	free(item->value);
	free(item->key);
	free(item);
}

MU_TEST(ht_destroy_item_tst)
{
	t_ht_item	*item;

	item = ht_new_item("bananas", "pajamas");
	mu_check(item != NULL);
	mu_assert_string_eq("bananas", item->key);
	mu_assert_string_eq("pajamas", item->value);
	ht_destroy_item(&item);
	mu_check(item == NULL);
}

MU_TEST(ht_insert_tst)
{
	t_hash_table	*table;
	t_ht_item	*item;

	table = ht_init();
	ht_insert(table, "chave", "value");
	_index = ht_get_index("chave");
	item = table->index_lists[_index]->content;
	mu_assert_string_eq("chave", item->key);
	mu_assert_string_eq("value", item->value);
	ht_destroy(&table);
}

MU_TEST_SUITE(hash_table_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);
	MU_RUN_TEST(ht_index_tst);
	MU_RUN_TEST(ht_init_tst);
	MU_RUN_TEST(ht_destroy_tst);
	MU_RUN_TEST(ht_new_item_tst);
	MU_RUN_TEST(ht_destroy_item_tst);
	MU_RUN_TEST(ht_insert_tst);
}

int	main(void)
{
	MU_RUN_SUITE(hash_table_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
