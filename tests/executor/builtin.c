/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:22:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/06 16:19:54 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_parse_list *_plist;

void setup(void)
{
	mock_initialize_shell();
}
void teardown(void)
{
	cleanup_shell();
}

MU_TEST(echo_tst)
{
	_plist = NULL;

	add_exec(&_plist, (char *[]){"echo", "garmonbozia", NULL});
	execute(_plist);
}

MU_TEST(cd_tst)
{
	_plist = NULL;
	add_exec(&_plist, (char *[]){"cd", ".", NULL});
	execute(_plist);

	_plist = NULL;
	add_exec(&_plist, (char *[]){"cd", "./sources", NULL});
	execute(_plist);

	_plist = NULL;
	add_exec(&_plist, (char *[]){"cd", "..", NULL});
	execute(_plist);
}

MU_TEST(pwd_tst)
{
	_plist = NULL;

	add_exec(&_plist, (char *[]){"pwd", NULL});
	execute(_plist);
}

MU_TEST(export_tst)
{
	_plist = NULL;

	add_exec(&_plist, (char *[]){"export", "no_assignment", "empty=", "foo=bar", NULL});
	execute(_plist);

	mu_check(NULL == envht_get("no_assignment"));
	mu_assert_string_eq("", envht_get("empty"));
	mu_assert_string_eq("bar", envht_get("foo"));
}

MU_TEST(unset_tst)
{
	_plist = NULL;

	envht_insert("garmon", "bozia");
	envht_insert("the", "chrome");
	envht_insert("refl", "ects");
	envht_insert("our", "image");
	add_exec(&_plist, (char *[]){"unset", "the", "our", NULL});
	execute(_plist);

	mu_assert_string_eq("bozia", envht_get("garmon"));
	mu_check(NULL == envht_get("the"));
	mu_assert_string_eq("ects", envht_get("refl"));
	mu_check(NULL == envht_get("our"));
}

MU_TEST(env_tst)
{
	_plist = NULL;

	add_exec(&_plist, (char *[]){"env", NULL});
	execute(_plist);
}

MU_TEST(exit_tst)
{
	_plist = NULL;
	pid_t pid;
	int wstatus;
	int bi_exit_status;

	add_exec(&_plist, (char *[]){"exit", NULL});
	pid = fork();
	if (pid == CHILD_PROCESS_ID)
	{
		execute(_plist);
		cleanup_shell();
	}
	mu_check(pid == wait(&wstatus));
	mu_assert_int_eq(0, WEXITSTATUS(wstatus));
}

MU_TEST(help_tst)
{
	_plist = NULL;

	add_exec(&_plist, (char *[]){"help", NULL});
	execute(_plist);
}

MU_TEST_SUITE(pipeline_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(echo_tst);
	MU_RUN_TEST(cd_tst);
	MU_RUN_TEST(pwd_tst);
	MU_RUN_TEST(export_tst);
	MU_RUN_TEST(unset_tst);
	MU_RUN_TEST(env_tst);
	MU_RUN_TEST(help_tst);
	MU_RUN_TEST(exit_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(pipeline_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
