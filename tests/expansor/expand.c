/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:14:28 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/06 13:55:37 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../tests.h"

static void test_expand_token(char *expected, char *token)
{
	char *expanded = expand(token);

	mu_assert_string_eq(expected, expanded);
	free(expanded);
}

void	setup(void)
{
	c()->envp = (char *[]){NULL};
	initilize_envht();
}
void	teardown(void)
{
	destroy_envht();
}

MU_TEST(single_variable)
{
	mu_check(true == envht_insert("foo", "bar"));

	test_expand_token("bar", "$foo");
	test_expand_token("\"bar\"", "\"$foo\"");
	test_expand_token("\'$foo\'", "\'$foo\'");
}

MU_TEST(multiple_variables)
{
	mu_check(true == envht_insert("foo", "bar"));
	mu_check(true == envht_insert("banana", "chocolate"));

	test_expand_token("testeandobarchocolate", "testeando$foo$banana");
	test_expand_token("testeando\"bar\"\'$banana\'", "testeando\"$foo\"\'$banana\'");
}

MU_TEST(example_tests)
{
	mu_check(true == envht_insert("foo", "42"));

	test_expand_token("foo'bar'", "foo'bar'");
	test_expand_token("42", "$foo");
	test_expand_token("bar42", "bar$foo");
	test_expand_token("'$foo'", "'$foo'");
	test_expand_token("baz42'bar'", "baz$foo'bar'");
	test_expand_token("baz42'$foo'", "baz$foo'$foo'");
	test_expand_token("\"42\"", "\"$foo\"");
	test_expand_token("baz42\"42\"", "baz$foo\"$foo\"");
	test_expand_token("baz42\"42'\"", "baz$foo\"$foo'\"");
	test_expand_token("'baz$foo'42''", "'baz$foo'$foo''");
	test_expand_token("42", "$foo");
	test_expand_token("bar42", "bar$foo");
	test_expand_token("\"baz42'42'\"", "\"baz$foo'$foo'\"");
}

MU_TEST_SUITE(test_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(single_variable);
	MU_RUN_TEST(multiple_variables);
	MU_RUN_TEST(example_tests);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
