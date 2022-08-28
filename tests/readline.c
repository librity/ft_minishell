/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2022/08/28 17:41:22 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void	example_setup(void)
{
}
static void	example_teardown(void)
{
}

/*
Achar um jeito de poder passar uma string pro write pelo teste.
*/

MU_TEST(readline_test)
{
	char	*user_line;

	user_line = get_user_line();
	mu_assert_string_eq("OIE", user_line);
}

MU_TEST(readline_test2)
{
	char	*user_line;

	user_line = get_user_line();
	mu_assert_string_eq("tchal", user_line);
}

MU_TEST(readline_test3)
{
	char	*user_line;

	mu_assert_string_eq("oie", get_user_line());
	mu_assert_string_eq("tchal", get_user_line());
}

MU_TEST(readline_test4)
{
	char	*result;
	char	*expected;

	expected = "This is a command";
	set_line_cmd("This is a command");
	result = line_cmd();
	mu_assert_string_eq(expected, result);
}

MU_TEST_SUITE(example_suite)
{
	MU_SUITE_CONFIGURE(&example_setup, &example_teardown);
	// MU_RUN_TEST(readline_test);
	// MU_RUN_TEST(readline_test2);
	// MU_RUN_TEST(readline_test3);
	MU_RUN_TEST(readline_test4);
}

int	main(void)
{
	MU_RUN_SUITE(example_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
