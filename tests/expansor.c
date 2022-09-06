/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:14:28 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/05 21:02:55 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

char	*value;

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

	value = expand_token("$foo");
	mu_assert_string_eq("bar", value);
	free(value);

	value = expand_token("\"$foo\"");
	mu_assert_string_eq("\"bar\"", value);
	free(value);

	value = expand_token("\'$foo\'");
	mu_assert_string_eq("\'$foo\'", value);
	free(value);
}

MU_TEST(multiple_variables)
{
	mu_check(true == envht_insert("foo", "bar"));
	mu_check(true == envht_insert("banana", "chocolate"));

	value = expand_token("testeando$foo$banana");
	mu_assert_string_eq("testeandobarchocolate", value);
	free(value);

	value = expand_token("testeando\"$foo\"\'$banana\'");
	mu_assert_string_eq("testeando\"bar\"\'$banana\'", value);
	free(value);
}

MU_TEST_SUITE(test_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(single_variable);
	MU_RUN_TEST(multiple_variables);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
