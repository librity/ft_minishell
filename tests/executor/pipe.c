/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:22:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/28 17:52:04 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_parse_list	*_plist;
t_parse	*_pnode;

void	setup(void)
{
	mock_initialize_shell();
}
void	teardown(void)
{
	cleanup_shell();
}

MU_TEST(e_tst)
{
	_plist = NULL;

	ft_dlst_add(&_plist, new_exec((char *[]){"ls", "-a", NULL}));

	execute_pipe(_plist);
	ft_dump_stdin();

	destroy_parse_list(&_plist);
}

MU_TEST(ep_e_tst)
{
	_plist = NULL;

	ft_dlst_add(&_plist, new_exec((char *[]){"ls", "-a", NULL}));
	ft_dlst_add(&_plist, new_pipe());
	ft_dlst_add(&_plist, new_exec((char *[]){"grep", "main", "main.c", NULL}));

	execute_pipe(_plist);
	ft_dump_stdin();

	execute_pipe(_plist->next->next);
	ft_dump_stdin();

	destroy_parse_list(&_plist);
}

MU_TEST(te_tst)
{
	_plist = NULL;

	add_truncate(&_plist, "tests/sandbox/te_tst");
	add_exec(&_plist, (char *[]){"ls", NULL});

	execute_pipe(_plist);
	ft_dump_stdin();

	destroy_parse_list(&_plist);
}

MU_TEST(ae_tst)
{
	_plist = NULL;

	add_append(&_plist, "tests/sandbox/ae_tst");
	add_exec(&_plist, (char *[]){"ls", NULL});

	execute_pipe(_plist);
	ft_dump_stdin();

	destroy_parse_list(&_plist);
}

MU_TEST(re_tst)
{
	_plist = NULL;

	add_read_file(&_plist, "tests/sandbox/re_tst");
	add_exec(&_plist, (char *[]){"grep", "a", NULL});

	execute_pipe(_plist);
	ft_dump_stdin();

	destroy_parse_list(&_plist);
}

MU_TEST(e_relative_tst)
{
	_plist = NULL;

	add_exec(&_plist, (char *[]){"tests/sandbox/ls", NULL});

	execute_pipe(_plist);
	ft_dump_stdin();

	destroy_parse_list(&_plist);
}

MU_TEST(e_absolute_tst)
{
	_plist = NULL;

	add_exec(&_plist, (char *[]){"/bin/ls", NULL});

	execute_pipe(_plist);
	ft_dump_stdin();

	destroy_parse_list(&_plist);
}

MU_TEST_SUITE(pipe_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	// ACCEPTABLE LEAKS: ls
	MU_RUN_TEST(e_tst);

	// ACCEPTABLE LEAKS: ls grep
	MU_RUN_TEST(ep_e_tst);

	// ACCEPTABLE LEAKS: ls
	MU_RUN_TEST(te_tst);

	// ACCEPTABLE LEAKS: ls
	MU_RUN_TEST(ae_tst);

	// ACCEPTABLE LEAKS: grep
	MU_RUN_TEST(re_tst);

	// ACCEPTABLE LEAKS: bash
	MU_RUN_TEST(e_relative_tst);

	// ACCEPTABLE LEAKS: ls
	MU_RUN_TEST(e_absolute_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(pipe_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
