/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/23 15:57:10 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

void	setup(void)
{
	mock_initialize_shell();
}
void	teardown(void)
{
	cleanup_shell();
}

MU_TEST(dump_tst)
{
	mu_check(0 == bi_env((char *[]){"env", NULL}));
}

MU_TEST(args_tst)
{
	mu_check(127 == bi_env((char *[]){"env", "sources", NULL}));
	mu_check(127 == bi_env((char *[]){"env", "main.c", NULL}));
	mu_check(127 == bi_env((char *[]){"env", "sources", "main.c", NULL}));
	mu_check(127 == bi_env((char *[]){"env", "sources", "dasdasda", NULL}));
}

MU_TEST(empty_tst)
{
	mu_check(1 == bi_env((char *[]){NULL}));
}

MU_TEST(null_tst)
{
	mu_check(1 == bi_env(NULL));
}

MU_TEST_SUITE(env_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(dump_tst);
	MU_RUN_TEST(args_tst);

	MU_RUN_TEST(empty_tst);
	MU_RUN_TEST(null_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(env_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
