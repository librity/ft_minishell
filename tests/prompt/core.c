/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/10/10 15:38:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

char	*_expected;
char	*_stdin;
char	*_result;
bool	_bool;

static void setup(void)
{
}
static void teardown(void)
{
	free_lalloc();
	rl_clear_history();
}

MU_TEST(trivial_tst)
{
	write_to_stdin_with_teardown("teste 1 test 2 teste 5\nasdasdas dadsa sdas ds", &teardown);

	_result = prompt();
	mu_assert_string_eq("teste 1 test 2 teste 5", _result);

	_result = prompt();
	mu_assert_string_eq("asdasdas dadsa sdas ds", _result);
}

MU_TEST(null_tst)
{
	write_to_stdin_with_teardown("teste 1 test 2 teste 5\nasdasdas dadsa sdas ds", &teardown);

	_result = prompt();
	mu_assert_string_eq("teste 1 test 2 teste 5", _result);

	write_to_stdin_with_teardown(NULL, &teardown);

	_result = prompt();
	mu_assert_string_eq(NULL, _result);

	_result = prompt();
	mu_assert_string_eq(NULL, _result);

	_result = prompt();
	mu_assert_string_eq(NULL, _result);
}

MU_TEST(newline_tst)
{
	write_to_stdin_with_teardown("\nteste 1 test 2 teste 5\nasdasdas dadsa sdas ds", &teardown);

	_result = prompt();
	mu_assert_string_eq("", _result);

	_result = prompt();
	mu_assert_string_eq("teste 1 test 2 teste 5", _result);

	_result = prompt();
	mu_assert_string_eq("asdasdas dadsa sdas ds", _result);
}

MU_TEST(multiple_lines_tst)
{
	write_to_stdin_with_teardown("t\ne\ns\nt\ne\n \n1\n \nt\ne\ns\nt\n \n2\n", &teardown);

	_result = prompt();
	mu_assert_string_eq("t", _result);

	_result = prompt();
	mu_assert_string_eq("e", _result);

	_result = prompt();
	mu_assert_string_eq("s", _result);

	_result = prompt();
	mu_assert_string_eq("t", _result);

	_result = prompt();
	mu_assert_string_eq("e", _result);

	_result = prompt();
	mu_assert_string_eq(" ", _result);

	_result = prompt();
	mu_assert_string_eq("1", _result);

	_result = prompt();
	mu_assert_string_eq(" ", _result);

	_result = prompt();
	mu_assert_string_eq("t", _result);

	_result = prompt();
	mu_assert_string_eq("e", _result);

	_result = prompt();
	mu_assert_string_eq("s", _result);

	_result = prompt();
	mu_assert_string_eq("t", _result);

	_result = prompt();
	mu_assert_string_eq(" ", _result);

	_result = prompt();
	mu_assert_string_eq("2", _result);

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

	MU_RUN_TEST(trivial_tst);
	MU_RUN_TEST(null_tst);
	MU_RUN_TEST(newline_tst);
	MU_RUN_TEST(multiple_lines_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(prompt_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
