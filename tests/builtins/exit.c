/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/24 18:57:19 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

static void	test_exit(int expected_status, char **tokens)
{
	pid_t	pid;
	int		wstatus;
	int		bi_exit_status;

	pid = fork();
	if (pid == CHILD_PROCESS_ID)
	{
		bi_exit_status = bi_exit(tokens);
		exit(bi_exit_status);
	}
	mu_check(pid == wait(&wstatus));
	mu_assert_int_eq(expected_status, WEXITSTATUS(wstatus));
}

void	setup(void)
{
	mock_initialize_shell();
	set_last_exit(0);
}
void	teardown(void)
{
	cleanup_shell();
}

MU_TEST(no_args_tst)
{
	set_last_exit(42);
	test_exit(42, (char *[]){"exit", NULL});

	set_last_exit(1);
	test_exit(1, (char *[]){"exit", NULL});

	set_last_exit(2);
	test_exit(2, (char *[]){"exit", NULL});

	set_last_exit(4);
	test_exit(4, (char *[]){"exit", NULL});

	set_last_exit(99);
	test_exit(99, (char *[]){"exit", NULL});

	set_last_exit(-42);
	test_exit(214, (char *[]){"exit", NULL});

	set_last_exit(0);
	test_exit(0, (char *[]){"exit", NULL});
}

MU_TEST(arg_tst)
{
	test_exit(0, (char *[]){"exit", "0", NULL});
	test_exit(1, (char *[]){"exit", "1", NULL});
	test_exit(2, (char *[]){"exit", "2", NULL});
	test_exit(4, (char *[]){"exit", "4", NULL});
	test_exit(42, (char *[]){"exit", "42", NULL});
	test_exit(214, (char *[]){"exit", "-42", NULL});
}

MU_TEST(bad_status_tst)
{
	test_exit(2, (char *[]){"exit", "sdasdad", NULL});
	test_exit(2, (char *[]){"exit", "dsads", "1", "10", NULL});
}

MU_TEST(too_many_arguments_tst)
{
	test_exit(1, (char *[]){"exit", "1", "sdasdad", NULL});
	test_exit(1, (char *[]){"exit", "1", "2", "10", "sdasdad", NULL});
}

MU_TEST_SUITE(exit_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(no_args_tst);
	MU_RUN_TEST(arg_tst);

	MU_RUN_TEST(bad_status_tst);
	MU_RUN_TEST(too_many_arguments_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(exit_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
