/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/24 15:55:17 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

char	**_strarr;

void	test_setup(void)
{
	mock_initialize_shell();
}
void	test_teardown(void)
{
	cleanup_shell();
}

MU_TEST(trivial_tst)
{
	_strarr = (char *[]){"name=wallas", "idade=19", "42=sp", "bo=zia",
		NULL};
	ht_insert_strarr(envht(), _strarr);

	mu_check(0 == bi_unset((char *[]){"unset", "name", "idade", NULL}));
	mu_check(false == ht_get(envht(), "name"));
	mu_check(false == ht_get(envht(), "idade"));
	mu_check(false != ht_get(envht(), "42"));
	mu_check(false != ht_get(envht(), "bo"));

}

MU_TEST(null_tst)
{
	char	*test = NULL;

	_strarr = NULL;
	mu_check(1 == bi_unset(_strarr));
	mu_check(1 == bi_unset(&test));
	mu_check(1 == bi_unset(NULL));

	mu_check(0 == bi_unset((char *[]){"unset", "name", "idade", NULL}));
}

MU_TEST(no_args_tst)
{
	mu_check(0 == bi_unset((char *[]){"unset", NULL}));
}

MU_TEST_SUITE(unset_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(trivial_tst);
	MU_RUN_TEST(null_tst);
	MU_RUN_TEST(no_args_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(unset_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
