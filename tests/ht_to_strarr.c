/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_to_strarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/09/05 00:27:34 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table.h"

t_hash_table	*_table;
char			**_strarr;

static void	setup(void)
{
}
static void	teardown(void)
{
}

MU_TEST(trivial_tst)
{
	_table = ht_new();
	ht_insert(_table, "foo", "bar");
	ht_insert(_table, "fizz", "buzz");
	ht_insert(_table, "gar", "mon");
	ht_insert(_table, "bo", "zia");

	_strarr = ht_to_strarr(_table);
	mu_check(4 == ft_strarr_len(_strarr));

	assert_in_strarr(_strarr, "foo=bar");
	assert_in_strarr(_strarr, "fizz=buzz");
	assert_in_strarr(_strarr, "gar=mon");
	assert_in_strarr(_strarr, "bo=zia");

	ft_free_strarr(_strarr);
	ht_destroy(&_table);
}

MU_TEST(empty_tst)
{
	_table = ht_new();

	_strarr = ht_to_strarr(_table);
	mu_check(0 == ft_strarr_len(_strarr));

	ft_free_strarr(_strarr);
	ht_destroy(&_table);
}

MU_TEST(null_tst)
{
	_strarr = ht_to_strarr(NULL);
	mu_check(NULL == _strarr);
}

MU_TEST_SUITE(to_strarr_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(trivial_tst);
	MU_RUN_TEST(empty_tst);
	MU_RUN_TEST(null_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(to_strarr_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
