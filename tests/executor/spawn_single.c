/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_single.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:22:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/16 15:32:07 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_parse_list	*_plist;
t_parse 		*_pnode;
pid_t			_pids[1];

void setup(void)
{
	mock_initialize_shell();
}
void teardown(void)
{
	cleanup_shell();
}

MU_TEST(e_tst)
{
	_plist = NULL;

	add_exec(&_plist, (char *[]){"ls", "-a", NULL});

	spawn_single_pipe(_plist, _pids);
	wait(NULL);
}

MU_TEST(ep_e_tst)
{
	_plist = NULL;

	add_exec(&_plist, (char *[]){"ls", "-a", NULL});
	add_exec(&_plist, (char *[]){"grep", "main", "main.c", NULL});

	spawn_single_pipe(_plist, _pids);
	spawn_single_pipe(_plist->next, _pids);

	wait(NULL);
	wait(NULL);
}

MU_TEST(te_tst)
{
	_plist = NULL;

	add_truncate(&_plist, "tests/sandbox/te_tst");
	add_exec(&_plist, (char *[]){"ls", NULL});

	spawn_single_pipe(_plist, _pids);
	wait(NULL);
}

MU_TEST(ae_tst)
{
	_plist = NULL;

	add_append(&_plist, "tests/sandbox/ae_tst");
	add_exec(&_plist, (char *[]){"ls", NULL});

	spawn_single_pipe(_plist, _pids);
	wait(NULL);
}

MU_TEST(re_tst)
{
	_plist = NULL;

	add_read_file(&_plist, "tests/sandbox/re_tst");
	add_exec(&_plist, (char *[]){"grep", "a", NULL});

	spawn_single_pipe(_plist, _pids);
	wait(NULL);
}

MU_TEST(e_relative_tst)
{
	_plist = NULL;

	add_exec(&_plist, (char *[]){"tests/sandbox/ls", NULL});

	spawn_single_pipe(_plist, _pids);
	wait(NULL);
}

MU_TEST(e_absolute_tst)
{
	_plist = NULL;

	add_exec(&_plist, (char *[]){"/bin/ls", NULL});

	spawn_single_pipe(_plist, _pids);
	wait(NULL);
}

MU_TEST(ls_tst)
{
	_plist = NULL;
	add_exec(&_plist, (char *[]){"ls", "sources", "tests", NULL});

	spawn_single_pipe(_plist, _pids);
	wait(NULL);
}

MU_TEST(cat_tst)
{
	_plist = NULL;
	add_exec(&_plist, (char *[]){"cat", "main.c", "Makefile", NULL});

	spawn_single_pipe(_plist, _pids);
	wait(NULL);
}

MU_TEST(cat_err_tst)
{
	_plist = NULL;
	add_exec(&_plist, (char *[]){"cat", "file1", "file2", NULL});

	spawn_single_pipe(_plist, _pids);
	wait(NULL);
}

MU_TEST_SUITE(pipe_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(e_tst);	   // ACCEPTABLE LEAKS: ls
	MU_RUN_TEST(ep_e_tst); // ACCEPTABLE LEAKS: ls grep

	MU_RUN_TEST(te_tst); // ACCEPTABLE LEAKS: ls
	MU_RUN_TEST(ae_tst); // ACCEPTABLE LEAKS: ls
	MU_RUN_TEST(re_tst); // ACCEPTABLE LEAKS: grep

	MU_RUN_TEST(e_relative_tst); // ACCEPTABLE LEAKS: bash
	MU_RUN_TEST(e_absolute_tst); // ACCEPTABLE LEAKS: ls

	MU_RUN_TEST(ls_tst); // ACCEPTABLE LEAKS: ls
	MU_RUN_TEST(cat_tst); // ACCEPTABLE LEAKS: cat
	MU_RUN_TEST(cat_err_tst); // ACCEPTABLE LEAKS: cat
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(pipe_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
