/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:22:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/06 17:05:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_parse_list *_plist;
t_parse *_pnode;

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

	execute_pipe(_plist);
	ft_dump_stdin();
}

MU_TEST(ep_e_tst)
{
	_plist = NULL;

	add_exec(&_plist, (char *[]){"ls", "-a", NULL});
	add_pipe(&_plist);
	add_exec(&_plist, (char *[]){"grep", "main", "main.c", NULL});

	execute_pipe(_plist);
	ft_dump_stdin();

	execute_pipe(_plist->next->next);
	ft_dump_stdin();
}

MU_TEST(te_tst)
{
	_plist = NULL;

	add_truncate(&_plist, "tests/sandbox/te_tst");
	add_exec(&_plist, (char *[]){"ls", NULL});

	execute_pipe(_plist);
	ft_dump_stdin();
}

MU_TEST(ae_tst)
{
	_plist = NULL;

	add_append(&_plist, "tests/sandbox/ae_tst");
	add_exec(&_plist, (char *[]){"ls", NULL});

	execute_pipe(_plist);
	ft_dump_stdin();
}

MU_TEST(re_tst)
{
	_plist = NULL;

	add_read_file(&_plist, "tests/sandbox/re_tst");
	add_exec(&_plist, (char *[]){"grep", "a", NULL});

	execute_pipe(_plist);
	ft_dump_stdin();
}

MU_TEST(e_relative_tst)
{
	_plist = NULL;

	add_exec(&_plist, (char *[]){"tests/sandbox/ls", NULL});

	execute_pipe(_plist);
	ft_dump_stdin();
}

MU_TEST(e_absolute_tst)
{
	_plist = NULL;

	add_exec(&_plist, (char *[]){"/bin/ls", NULL});

	execute_pipe(_plist);
	ft_dump_stdin();
}

MU_TEST(ls_tst)
{
	_plist = NULL;
	add_exec(&_plist, (char *[]){"ls", "sources", "tests", NULL});

	execute_pipe(_plist);
	ft_dump_stdin();
}

MU_TEST(cat_tst)
{
	_plist = NULL;
	add_exec(&_plist, (char *[]){"cat", "main.c", "Makefile", NULL});

	execute_pipe(_plist);
	ft_dump_stdin();
}

MU_TEST(cat_err_tst)
{
	_plist = NULL;
	add_exec(&_plist, (char *[]){"cat", "file1", "file2", NULL});

	execute_pipe(_plist);
	ft_dump_stdin();
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
