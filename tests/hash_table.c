/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/08/30 16:16:30 by lpaulo-m         ###   ########.fr       */
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

MU_TEST_SUITE(hash_table_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);
	MU_RUN_TEST(ht_index_tst);
	MU_RUN_TEST(ht_init_tst);
	MU_RUN_TEST(ht_destroy_tst);
}

int	main(void)
{
	MU_RUN_SUITE(hash_table_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
