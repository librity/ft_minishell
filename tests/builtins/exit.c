/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/23 17:22:13 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

pid_t _pid;
int _wstatus;

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
	_pid = fork();
	if (_pid == CHILD_PROCESS_ID)
		bi_exit((char *[]){"exit", NULL});
	mu_check(_pid == wait(&_wstatus));
	mu_assert_int_eq(EXIT_SUCCESS, WEXITSTATUS(_wstatus));
}

MU_TEST(arg_tst)
{
	_pid = fork();
	if (_pid == CHILD_PROCESS_ID)
		bi_exit((char *[]){"exit", "0", NULL});
	mu_check(_pid == wait(&_wstatus));
	mu_assert_int_eq(0, WEXITSTATUS(_wstatus));

	_pid = fork();
	if (_pid == CHILD_PROCESS_ID)
		bi_exit((char *[]){"exit", "1", NULL});
	mu_check(_pid == wait(&_wstatus));
	mu_assert_int_eq(1, WEXITSTATUS(_wstatus));

	_pid = fork();
	if (_pid == CHILD_PROCESS_ID)
		bi_exit((char *[]){"exit", "2", NULL});
	mu_check(_pid == wait(&_wstatus));
	mu_assert_int_eq(2, WEXITSTATUS(_wstatus));

	_pid = fork();
	if (_pid == CHILD_PROCESS_ID)
		bi_exit((char *[]){"exit", "42", NULL});
	mu_check(_pid == wait(&_wstatus));
	mu_assert_int_eq(42, WEXITSTATUS(_wstatus));

	_pid = fork();
	if (_pid == CHILD_PROCESS_ID)
		bi_exit((char *[]){"exit", "-42", NULL});
	mu_check(_pid == wait(&_wstatus));
	mu_assert_int_eq(214, WEXITSTATUS(_wstatus));
}

MU_TEST(bad_status_tst)
{
	int status;

	_pid = fork();
	if (_pid == CHILD_PROCESS_ID)
		bi_exit((char *[]){"exit", "sdasdad", NULL});
	mu_check(_pid == wait(&_wstatus));
	mu_assert_int_eq(2, WEXITSTATUS(_wstatus));

	status = bi_exit((char *[]){"exit", "dsads", "1", "10", NULL});
	mu_check(_pid == wait(&_wstatus));
	mu_assert_int_eq(2, WEXITSTATUS(_wstatus));
}

MU_TEST(too_many_arguments_tst)
{
	_pid = fork();
	if (_pid == CHILD_PROCESS_ID)
		bi_exit((char *[]){"exit", "1", "sdasdad", NULL});
	mu_check(_pid == wait(&_wstatus));
	mu_assert_int_eq(1, WEXITSTATUS(_wstatus));

	_pid = fork();
	if (_pid == CHILD_PROCESS_ID)
		bi_exit((char *[]){"exit", "1", "2", "10", "sdasdad", NULL});
	mu_check(_pid == wait(&_wstatus));
	mu_assert_int_eq(1, WEXITSTATUS(_wstatus));
}

MU_TEST_SUITE(exit_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(trivial_tst);
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
