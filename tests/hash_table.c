/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/08/30 18:03:56 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int				_index;
int				expected;
t_ht_item		*item;
t_hash_table	*table;

void	setup(void)
{
}
void	teardown(void)
{
}

MU_TEST(index_tst)
{
	_index = ht_get_index("abc");
	expected = (int)(md5_sum("abc") % HASH_TABLE_SIZE);
	mu_assert_int_eq(expected, _index);
}

MU_TEST(init_tst)
{
	table = ht_init();
	mu_check(table != NULL);
	mu_check(table->size == HASH_TABLE_SIZE);
	mu_check(table->count == 0);
	free(table->index_lists);
	free(table);
}

MU_TEST(destroy_tst)
{
	table = ht_init();
	mu_check(table != NULL);
	ht_destroy(&table);
	mu_check(table == NULL);
}

MU_TEST(new_item_tst)
{
	item = ht_new_item("abc", "value");
	mu_check(item != NULL);
	mu_assert_string_eq("abc", item->key);
	mu_assert_string_eq("value", item->value);
	free(item->value);
	free(item->key);
	free(item);
}

MU_TEST(destroy_item_tst)
{
	item = ht_new_item("bananas", "pajamas");
	mu_check(item != NULL);
	mu_assert_string_eq("bananas", item->key);
	mu_assert_string_eq("pajamas", item->value);
	ht_destroy_item(&item);
	mu_check(item == NULL);
}

MU_TEST(insert_one_tst)
{
	table = ht_init();
	ht_insert(table, "chave", "value");
	mu_check(table->count == 1);
	_index = ht_get_index("chave");
	item = table->index_lists[_index]->content;
	mu_assert_string_eq("chave", item->key);
	mu_assert_string_eq("value", item->value);
	ht_destroy(&table);
}

MU_TEST(reinsert_tst)
{
	table = ht_init();
	ht_insert(table, "chave", "a");
	ht_insert(table, "chave", "b");
	mu_check(table->count == 1);
	_index = ht_get_index("chave");
	item = table->index_lists[_index]->content;
	mu_assert_string_eq("chave", item->key);
	mu_assert_string_eq("b", item->value);
	ht_destroy(&table);
}

MU_TEST_SUITE(hash_table_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);
	MU_RUN_TEST(index_tst);
	MU_RUN_TEST(init_tst);
	MU_RUN_TEST(destroy_tst);
	MU_RUN_TEST(new_item_tst);
	MU_RUN_TEST(destroy_item_tst);
	MU_RUN_TEST(insert_one_tst);
	MU_RUN_TEST(reinsert_tst);
}

int	main(void)
{
	MU_RUN_SUITE(hash_table_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
