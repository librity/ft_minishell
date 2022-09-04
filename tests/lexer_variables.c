/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_variables.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/09/04 20:49:47 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table.h"

t_hash_table	*_table;
char			*_str;
char			**_strarr;

static void test_tokenize_variable(char **expected, char *raw_variable)
{
	char **tokens = tokenize_variable(raw_variable);

	assert_strarr_eq(expected, tokens);
	ft_free_strarr(tokens);
}

static void	setup(void)
{
}
static void	teardown(void)
{
}

MU_TEST(tokenize_variable_tst)
{
	_str = "a=b";
	_strarr = (char *[]){ "a", "b", NULL};
	test_tokenize_variable(_strarr, _str);

	_str = "foo=bar";
	_strarr = (char *[]){ "foo", "bar", NULL};
	test_tokenize_variable(_strarr, _str);

	_str = "PATH=/home/username/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin";
	_strarr = (char *[]){ "PATH", "/home/username/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin", NULL};
	test_tokenize_variable(_strarr, _str);
}

MU_TEST(tokenize_variable_null_tst)
{
	_str = ft_strdup("a=b");
	*(_str + 1) = DELIMITER;
	_strarr = tokenize_variable(_str);
	mu_check(NULL == _strarr);
	free(_str);

	_strarr = tokenize_variable("abc");
	mu_check(NULL == _strarr);

	_strarr = tokenize_variable("");
	mu_check(NULL == _strarr);

	_strarr = tokenize_variable(NULL);
	mu_check(NULL == _strarr);
}


MU_TEST_SUITE(hash_table_from_array_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);
	MU_RUN_TEST(tokenize_variable_tst);
	MU_RUN_TEST(tokenize_variable_null_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(hash_table_from_array_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
