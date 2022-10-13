/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:14:28 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/11 15:41:28 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../tests.h"

static void test_expand(char *expected, char *input)
{
	char *expanded = expand(input);

	mu_assert_string_eq(expected, expanded);
	free(expanded);
}

void	setup(void)
{
	c()->envp = (char *[]){NULL};
	initialize_envht();
	initialize_last_exit();
}
void	teardown(void)
{
	destroy_envht();
	destroy_last_exit();
}

MU_TEST(single_variable)
{
	mu_check(true == envht_insert("foo", "bar"));

	test_expand("bar", "$foo");
	test_expand("\"bar\"", "\"$foo\"");
	test_expand("\'$foo\'", "\'$foo\'");
}

MU_TEST(multiple_variables)
{
	mu_check(true == envht_insert("foo", "bar"));
	mu_check(true == envht_insert("banana", "chocolate"));

	test_expand("testeandobarchocolate", "testeando$foo$banana");
	test_expand("testeando\"bar\"\'$banana\'", "testeando\"$foo\"\'$banana\'");
	test_expand("testeando\"chocolate\"\'$foo\'", "testeando\"$banana\"\'$foo\'");
}

MU_TEST(docs_tests)
{
	mu_check(true == envht_insert("foo", "42"));

	test_expand("foo'bar'", "foo'bar'");
	test_expand("42", "$foo");
	test_expand("bar42", "bar$foo");
	test_expand("'$foo'", "'$foo'");
	test_expand("baz42'bar'", "baz$foo'bar'");
	test_expand("baz42'$foo'", "baz$foo'$foo'");
	test_expand("\"42\"", "\"$foo\"");
	test_expand("baz42\"42\"", "baz$foo\"$foo\"");
	test_expand("baz42\"42'\"", "baz$foo\"$foo'\"");
	test_expand("'baz$foo'42''", "'baz$foo'$foo''");
	test_expand("42", "$foo");
	test_expand("bar42", "bar$foo");
	test_expand("\"baz42'42'\"", "\"baz$foo'$foo'\"");
}

MU_TEST(last_exit_tests)
{
	test_expand("0", "$?");
	mu_check(true == envht_insert("banana", "chocolate"));

	set_last_exit(42);
	test_expand("42", "$?");
	test_expand("bar42", "bar$?");
	test_expand("'$?'", "'$?'");
	test_expand("baz42'bar'", "baz$?'bar'");
	test_expand("baz42'$?'", "baz$?'$?'");
	test_expand("\"42\"", "\"$?\"");
	test_expand("baz42\"42\"", "baz$?\"$?\"");
	test_expand("baz42\"42'\"", "baz$?\"$?'\"");
	test_expand("'baz$?'42''", "'baz$?'$?''");
	test_expand("42", "$?");
	test_expand("bar42", "bar$?");
	test_expand("\"baz42'42'\"", "\"baz$?'$?'\"");

	test_expand("\"42\"", "\"$?\"");
	test_expand("\'$?\'", "\'$?\'");
	test_expand("testeando42chocolate", "testeando$?$banana");
	test_expand("testeando\"42\"\'$banana\'", "testeando\"$?\"\'$banana\'");
	test_expand("testeando\"chocolate\"\'$?\'", "testeando\"$banana\"\'$?\'");
}

MU_TEST(no_var_tests)
{
	test_expand("", "$no_var");
	test_expand("abc", "abc$no_var");

	test_expand("\"abc\"", "\"abc\"$no_var");
	test_expand("\"abc\"", "$no_var\"abc\"");
	test_expand("abc\"abc\"", "abc$no_var\"abc\"");

	test_expand("\'abc\'", "\'abc\'$no_var");
	test_expand("\'abc\'", "$no_var\'abc\'");
	test_expand("abc\'abc\'", "abc$no_var\'abc\'");

	test_expand("\"\"", "\"$no_var\"");
	test_expand("\'$no_var\'", "\'$no_var\'");
}

MU_TEST(empty_tests)
{
	test_expand("", "");
}

MU_TEST(null_tests)
{
	mu_check(NULL == expand(NULL));
}

MU_TEST_SUITE(test_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(single_variable);
	MU_RUN_TEST(multiple_variables);
	MU_RUN_TEST(docs_tests);
	MU_RUN_TEST(last_exit_tests);

	MU_RUN_TEST(no_var_tests);

	MU_RUN_TEST(empty_tests);
	MU_RUN_TEST(null_tests);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
