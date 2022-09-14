/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/14 15:43:32 by lpaulo-m         ###   ########.fr       */
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

MU_TEST(trivial_tst)
{
	mu_check(true == cd((char *[]){"cd", "sources", NULL}));
	mu_check(true == pwd((char *[]){"pwd", NULL}));

	mu_check(true == cd((char *[]){"cd", "..", NULL}));
	mu_check(true == pwd((char *[]){"pwd", NULL}));
}

MU_TEST(args_tst)
{
	mu_check(false == pwd((char *[]){"pwd", "a", NULL}));
	mu_check(false == pwd((char *[]){"pwd", "b", "c", NULL}));
	mu_check(false == pwd((char *[]){"pwd", "fire", "walk", "with", "me", NULL}));
}

MU_TEST_SUITE(pwd_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(trivial_tst);
	MU_RUN_TEST(args_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(pwd_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
