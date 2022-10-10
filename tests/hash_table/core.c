/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/10/10 15:41:47 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table.h"

int				_int;

static void	setup(void)
{
}
static void	teardown(void)
{
}

MU_TEST(index_tst)
{
	g_index = ht_get_index("abc");
	_int = (int)(md5_sum("abc") % HASH_TABLE_SIZE);
	mu_assert_int_eq(_int, g_index);
}

MU_TEST(index_empty_tst)
{
	g_index = ht_get_index("");
	_int = (int)(md5_sum("") % HASH_TABLE_SIZE);
	mu_assert_int_eq(_int, g_index);

	g_index = ht_get_index("");
	_int = (int)(md5_sum("") % HASH_TABLE_SIZE);
	mu_assert_int_eq(_int, g_index);
}

MU_TEST(index_null_tst)
{
	g_index = ht_get_index(NULL);
	mu_assert_int_eq(HT_BAD_INDEX, g_index);
}

MU_TEST(new_tst)
{
	g_table = ht_new();
	mu_check(g_table != NULL);
	mu_check(g_table->size == HASH_TABLE_SIZE);
	mu_check(g_table->count == 0);
	free(g_table->index_lists);
	free(g_table);
}

MU_TEST(destroy_tst)
{
	g_table = ht_new();
	mu_check(g_table != NULL);
	ht_destroy(&g_table);
	mu_check(g_table == NULL);
}

MU_TEST(destroy_null_tst)
{
	supress_stdout();

	ht_destroy(NULL);

	g_table = NULL;
	ht_destroy(&g_table);

	restore_stdout();
}

MU_TEST_SUITE(hash_table_core_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(index_tst);
	MU_RUN_TEST(index_empty_tst);
	MU_RUN_TEST(index_null_tst);

	MU_RUN_TEST(new_tst);

	MU_RUN_TEST(destroy_tst);
	MU_RUN_TEST(destroy_null_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(hash_table_core_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
