/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kuhn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:14:28 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/11 15:42:13 by lpaulo-m         ###   ########.fr       */
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

MU_TEST(dont_expand_tests)
{
	test_expand(
		"echo \"> >> < * ? [ ] | ; [ ] || && ( ) & # $  <<\"",
		"echo \"> >> < * ? [ ] | ; [ ] || && ( ) & # $  <<\"");
}

MU_TEST_SUITE(test_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(dont_expand_tests);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
