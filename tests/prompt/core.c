/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/10/07 15:53:01 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

char	*_expected;
char	*_stdin;
char	*_result;
bool	_bool;

static void	setup(void)
{
}
static void	teardown(void)
{
}

MU_TEST(get_line_cmd_tst)
{
	write_to_stdin("teste 1 test 2 teste 5\nasdasdas dadsa sdas ds");
	_result = prompt();
	mu_assert_string_eq("teste 1 test 2 teste 5", _result);
	free(_result);

	write_to_stdin(NULL);
	_result = prompt();
	mu_assert_string_eq(NULL, _result);
	free(_result);

	_result = prompt();
	mu_assert_string_eq(NULL, _result);
	free(_result);

	_result = prompt();
	mu_assert_string_eq(NULL, _result);
	free(_result);
}

MU_TEST(get_basic_tst)
{

	write_to_stdin("teste 1 test 2 teste 5\nasdasdas dadsa sdas ds");
	_result = prompt();
	mu_assert_string_eq("teste 1 test 2 teste 5", _result);
	free(_result);

	_result = prompt();
	mu_assert_string_eq("asdasdas dadsa sdas ds", _result);
	free(_result);
}

MU_TEST(get_medium_tst)
{
	write_to_stdin("\n\n\n\n\nteste 1 test 2 teste 5\n\n\nasdasdas dadsa sdas ds");
	_result = prompt();
	mu_assert_string_eq("teste 1 test 2 teste 5", _result);
	free(_result);

	_result = prompt();
	mu_assert_string_eq("asdasdas dadsa sdas ds", _result);
	free(_result);
}

MU_TEST(get_advanced_tst)
{

	write_to_stdin("\nt\n\ne\ns\nt\ne\n \n1\n \nt\ne\ns\nt\n \n2\n");
	_result = prompt();
	mu_assert_string_eq("t", _result);
	free(_result);

	_result = prompt();
	mu_assert_string_eq("e", _result);
	free(_result);

	_result = prompt();
	mu_assert_string_eq("s", _result);
	free(_result);

	_result = prompt();
	mu_assert_string_eq("t", _result);
	free(_result);

	_result = prompt();
	mu_assert_string_eq("e", _result);
	free(_result);

	_result = prompt();
	mu_assert_string_eq(" ", _result);
	free(_result);

	_result = prompt();
	mu_assert_string_eq("1", _result);
	free(_result);

	_result = prompt();
	mu_assert_string_eq(" ", _result);
	free(_result);

	_result = prompt();
	mu_assert_string_eq("t", _result);
	free(_result);

	_result = prompt();
	mu_assert_string_eq("e", _result);
	free(_result);

	_result = prompt();
	mu_assert_string_eq("s", _result);
	free(_result);

	_result = prompt();
	mu_assert_string_eq("t", _result);
	free(_result);

	_result = prompt();
	mu_assert_string_eq(" ", _result);
	free(_result);

	_result = prompt();
	mu_assert_string_eq("2", _result);
	free(_result);

	_result = prompt();
	mu_check(NULL == _result);

	_result = prompt();
	mu_check(NULL == _result);

	_result = prompt();
	mu_check(NULL == _result);
}

MU_TEST_SUITE(prompt_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(get_line_cmd_tst);
	MU_RUN_TEST(get_basic_tst);
	MU_RUN_TEST(get_medium_tst);
	MU_RUN_TEST(get_advanced_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(prompt_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
