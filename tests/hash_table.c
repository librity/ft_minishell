/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/09/01 14:40:27 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int				_index;
int				expected;
t_dlist			*node;
t_ht_item		*item;
t_hash_table	*table;
char			*value;
bool			_bool;

static void	test_ht_item(t_ht_item *_item,
							char *expected_key,
							char *expected_value)
{
	mu_check(_item != NULL);
	mu_assert_string_eq(expected_key, _item->key);
	mu_assert_string_eq(expected_value, _item->value);
}

static void	seed_ht(void)
{
	ht_insert(table, "foo", "bar");
	ht_insert(table, "baz", "fizz");
	ht_insert(table, "buzz", "crash");
}

static void	seed_ht_fixed_index(void)
{
	_index = 42;

	ht_insert_in_index(table, "foo", "bar", _index);
	ht_insert_in_index(table, "baz", "fizz", _index);
	ht_insert_in_index(table, "buzz", "crash", _index);
}

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

MU_TEST(index_empty_tst)
{
	_index = ht_get_index("");
	expected = (int)(md5_sum("") % HASH_TABLE_SIZE);
	mu_assert_int_eq(expected, _index);

	_index = ht_get_index("");
	expected = (int)(md5_sum("") % HASH_TABLE_SIZE);
	mu_assert_int_eq(expected, _index);
}

MU_TEST(index_null_tst)
{
	_index = ht_get_index(NULL);
	mu_assert_int_eq(HT_BAD_INDEX, _index);
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

/**
 * TODO: Remover a warning to STDOUT
 * e verificar que o destory imprimiu a warning.
 */
MU_TEST(destroy_null_tst)
{
	ht_destroy(NULL);

	table = NULL;
	ht_destroy(&table);
}

MU_TEST(new_item_tst)
{
	item = ht_new_item("abc", "value");
	test_ht_item(item, "abc", "value");

	ht_destroy_item(&item);
}

MU_TEST(new_item_empty_tst)
{
	item = ht_new_item("", "value");
	test_ht_item(item, "", "value");
	ht_destroy_item(&item);

	item = ht_new_item("abc", "");
	test_ht_item(item, "abc", "");
	ht_destroy_item(&item);
}

MU_TEST(new_item_null_tst)
{
	item = ht_new_item(NULL, "value");
	mu_check(item == NULL);

	item = ht_new_item("abc", NULL);
	mu_check(item == NULL);
}

MU_TEST(destroy_item_tst)
{
	item = ht_new_item("bananas", "pajamas");
	test_ht_item(item, "bananas", "pajamas");

	ht_destroy_item(&item);
	mu_check(item == NULL);
}

/**
 * TODO: Remover a warning to STDOUT
 * e verificar que o destory imprimiu a warning.
 */
MU_TEST(destroy_item_null_tst)
{
	ht_destroy_item(NULL);

	item = NULL;
	ht_destroy_item(&item);
}

MU_TEST(insert_one_tst)
{
	table = ht_init();
	_bool = ht_insert(table, "chave", "value");
	mu_check(_bool == true);

	mu_check(table->count == 1);
	_index = ht_get_index("chave");
	item = table->index_lists[_index]->content;
	test_ht_item(item, "chave", "value");

	ht_destroy(&table);
}

MU_TEST(insert_two_tst)
{
	table = ht_init();
	ht_insert(table, "mario", "luigi");
	mu_check(table->count == 1);
	ht_insert(table, "mamma", "mia");
	mu_check(table->count == 2);

	_index = ht_get_index("mario");
	item = table->index_lists[_index]->content;
	test_ht_item(item, "mario", "luigi");

	_index = ht_get_index("mamma");
	item = table->index_lists[_index]->content;
	test_ht_item(item, "mamma", "mia");

	ht_destroy(&table);
}

MU_TEST(reinsertion_tst)
{
	table = ht_init();
	ht_insert(table, "chave", "a");
	ht_insert(table, "chave", "b");

	mu_check(table->count == 1);
	_index = ht_get_index("chave");
	item = table->index_lists[_index]->content;
	test_ht_item(item, "chave", "b");

	ht_destroy(&table);
}

MU_TEST(collision_tst)
{
	table = ht_init();
	seed_ht_fixed_index();

	item = table->index_lists[_index]->content;
	test_ht_item(item, "buzz", "crash");

	item = table->index_lists[_index]->next->content;
	test_ht_item(item, "baz", "fizz");

	item = table->index_lists[_index]->next->next->content;
	test_ht_item(item, "foo", "bar");

	ht_destroy(&table);
}

MU_TEST(collision_reinsertion_tst)
{
	table = ht_init();
	seed_ht_fixed_index();

	ht_insert_in_index(table, "baz", "crash", _index);
	mu_check(table->count == 3);

	item = table->index_lists[_index]->next->content;
	test_ht_item(item, "baz", "crash");

	ht_destroy(&table);
}

MU_TEST(insert_empty_tst)
{
	table = ht_init();

	ht_insert(table, "", "value");
	mu_check(table->count == 1);
	_index = ht_get_index("");
	item = table->index_lists[_index]->content;
	test_ht_item(item, "", "value");

	ht_insert(table, "chave", "");
	mu_check(table->count == 2);
	_index = ht_get_index("chave");
	item = table->index_lists[_index]->content;
	test_ht_item(item, "chave", "");

	ht_destroy(&table);
}

MU_TEST(insert_null_tst)
{
	table = ht_init();

	_bool = ht_insert(NULL, "key", "value");
	mu_check(_bool == false);

	_bool = ht_insert(table, NULL, "value");
	mu_check(_bool == false);
	mu_check(table->count == 0);

	_bool = ht_insert(table, "chave", NULL);
	mu_check(_bool == false);
	mu_check(table->count == 0);

	ht_destroy(&table);
}

MU_TEST(get_tst)
{
	table = ht_init();
	seed_ht();

	value = ht_get(table, "foo");
	mu_assert_string_eq("bar", value);

	value = ht_get(table, "baz");
	mu_assert_string_eq("fizz", value);

	value = ht_get(table, "buzz");
	mu_assert_string_eq("crash", value);

	ht_destroy(&table);
}

MU_TEST(get_bad_key_tst)
{
	table = ht_init();
	seed_ht();

	value = ht_get(table, "idontexist");
	mu_check(value == NULL);

	value = ht_get(table, "idontexisteither");
	mu_check(value == NULL);

	value = ht_get(table, "idontexist");
	mu_check(value == NULL);

	value = ht_get(table, "are we there yet?");
	mu_check(value == NULL);

	ht_destroy(&table);
}

MU_TEST(get_reinsertion_tst)
{
	table = ht_init();
	seed_ht();

	ht_insert(table, "baz", "crash");
	value = ht_get(table, "baz");
	mu_assert_string_eq("crash", value);

	ht_destroy(&table);
}

MU_TEST(get_empty_tst)
{
	table = ht_init();

	ht_insert(table, "", "bar");
	value = ht_get(table, "");
	mu_assert_string_eq("bar", value);

	ht_insert(table, "foo", "");
	value = ht_get(table, "foo");
	mu_assert_string_eq("", value);

	ht_destroy(&table);
}

MU_TEST(get_null_tst)
{
	table = ht_init();

	value = ht_get(NULL, "foo");
	mu_check(value == NULL);

	value = ht_get(table, NULL);
	mu_check(value == NULL);

	ht_destroy(&table);
}

MU_TEST(delete_tst)
{
	table = ht_init();
	seed_ht();

	ht_delete(table, "foo");
	mu_check(table->count == 2);
	value = ht_get(table, "foo");
	mu_check(value == NULL);

	ht_delete(table, "baz");
	mu_check(table->count == 1);
	value = ht_get(table, "baz");
	mu_check(value == NULL);

	ht_delete(table, "buzz");
	mu_check(table->count == 0);
	value = ht_get(table, "buzz");
	mu_check(value == NULL);

	ht_destroy(&table);
}

MU_TEST(delete_twice_tst)
{
	table = ht_init();
	seed_ht();

	ht_delete(table, "baz");
	mu_check(table->count == 2);
	value = ht_get(table, "baz");
	mu_check(value == NULL);

	ht_delete(table, "baz");
	mu_check(table->count == 2);
	value = ht_get(table, "baz");
	mu_check(value == NULL);

	ht_destroy(&table);
}

MU_TEST(delete_same_index_tst)
{
	table = ht_init();
	seed_ht_fixed_index();
	ht_insert_in_index(table, "bada", "bing", _index);
	mu_check(table->count == 4);

	{
		ht_delete_in_index(table, "foo", _index);
		mu_check(table->count == 3);
		node = table->index_lists[_index]->next->next->next;
		mu_check(node == NULL);
		item = table->index_lists[_index]->next->next->content;
		test_ht_item(item, "baz", "fizz");
		item = table->index_lists[_index]->next->content;
		test_ht_item(item, "buzz", "crash");
		item = table->index_lists[_index]->content;
		test_ht_item(item, "bada", "bing");
	}

	{
		ht_delete_in_index(table, "buzz", _index);
		mu_check(table->count == 2);
		node = table->index_lists[_index]->next->next;
		mu_check(node == NULL);
		item = table->index_lists[_index]->next->content;
		test_ht_item(item, "baz", "fizz");
		item = table->index_lists[_index]->content;
		test_ht_item(item, "bada", "bing");
	}

	{
		ht_delete_in_index(table, "baz", _index);
		mu_check(table->count == 1);
		node = table->index_lists[_index]->next;
		mu_check(node == NULL);
		item = table->index_lists[_index]->content;
		test_ht_item(item, "bada", "bing");
	}

	{
		ht_delete_in_index(table, "bada", _index);
		mu_check(table->count == 0);
		node = table->index_lists[_index];
		mu_check(node == NULL);
	}

	{
		ht_delete_in_index(table, "bada", _index);
		mu_check(table->count == 0);
		node = table->index_lists[_index];
		mu_check(node == NULL);
	}

	ht_destroy(&table);
}

MU_TEST(delete_empty_tst)
{
	table = ht_init();

	_bool = ht_delete(table, "");
	mu_check(_bool == false);

	ht_insert(table, "", "value");
	_bool = ht_delete(table, "");
	mu_check(_bool == true);

	_bool = ht_delete(table, "");
	mu_check(_bool == false);

	ht_destroy(&table);
}

MU_TEST(delete_null_tst)
{
	table = ht_init();

	_bool = ht_delete(NULL, "key");
	mu_check(_bool == false);

	_bool = ht_delete(table, NULL);
	mu_check(_bool == false);

	ht_destroy(&table);
}

MU_TEST_SUITE(hash_table_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(index_tst);
	MU_RUN_TEST(index_empty_tst);
	MU_RUN_TEST(index_null_tst);

	MU_RUN_TEST(init_tst);

	MU_RUN_TEST(destroy_tst);
	MU_RUN_TEST(destroy_null_tst);

	MU_RUN_TEST(new_item_tst);
	MU_RUN_TEST(new_item_empty_tst);
	MU_RUN_TEST(new_item_null_tst);

	MU_RUN_TEST(destroy_item_tst);
	MU_RUN_TEST(destroy_item_null_tst);

	MU_RUN_TEST(insert_one_tst);
	MU_RUN_TEST(insert_two_tst);
	MU_RUN_TEST(reinsertion_tst);
	MU_RUN_TEST(collision_tst);
	MU_RUN_TEST(collision_reinsertion_tst);
	MU_RUN_TEST(insert_empty_tst);
	MU_RUN_TEST(insert_null_tst);

	MU_RUN_TEST(get_tst);
	MU_RUN_TEST(get_bad_key_tst);
	MU_RUN_TEST(get_reinsertion_tst);
	MU_RUN_TEST(get_empty_tst);
	MU_RUN_TEST(get_null_tst);

	MU_RUN_TEST(delete_tst);
	MU_RUN_TEST(delete_twice_tst);
	MU_RUN_TEST(delete_same_index_tst);
	MU_RUN_TEST(delete_empty_tst);
	MU_RUN_TEST(delete_null_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(hash_table_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
