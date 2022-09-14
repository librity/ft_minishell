/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/14 15:30:28 by lpaulo-m         ###   ########.fr       */
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
	mu_check(true == echo((char *[]){"echo", "sources", NULL}));
	mu_check(true == echo((char *[]){"echo", "garmonbozia", NULL}));
	mu_check(true == echo((char *[]){"echo", "sources", "asdsad", NULL}));
	mu_check(true == echo((char *[]){"echo", "a", "b", "c", "d", "e", NULL}));
	mu_check(true == echo((char *[]){"echo", NULL}));
}

MU_TEST(line_break_tst)
{
	mu_check(true == echo((char *[]){"echo", "-n", "sources", NULL}));
	mu_check(true == echo((char *[]){"echo", "-n", "garmonbozia", NULL}));
	mu_check(true == echo((char *[]){"echo", "sources", "-n", "asdsad", NULL}));
	mu_check(true == echo((char *[]){"echo", "a", "b", "c", "-n", "d", "e", NULL}));
	mu_check(true == echo((char *[]){"echo", "-n", NULL}));
}


MU_TEST_SUITE(echo_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(trivial_tst);
	MU_RUN_TEST(line_break_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(echo_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
