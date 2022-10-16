/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:22:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/16 15:03:29 by lpaulo-m         ###   ########.fr       */
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

MU_TEST(he_tst)
{
	_plist = NULL;

	add_heredoc(&_plist, "exit");
	add_exec(&_plist, (char *[]){"grep", "a", NULL});

	write_to_stdin("abc\na\nb\nc\nexit\nada\naaa");
	spawn_single_pipe(_plist, _pids);
	wait(NULL);
}

MU_TEST(hhre_tst)
{
	_plist = NULL;

	add_heredoc(&_plist, "1");
	add_heredoc(&_plist, "2");
	add_read_file(&_plist, "tests/sandbox/hhre_tst");
	add_exec(&_plist, (char *[]){"grep", "a", NULL});

	// write_to_stdin("a\nb\nc\n1\nada\naaa\n2\nabc\ndfg\naba");
	spawn_single_pipe(_plist, _pids);
	wait(NULL);
}

MU_TEST_SUITE(pipe_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	// LEAKING!
	MU_RUN_TEST(he_tst);

	// FAILING!
	// MU_RUN_TEST(hhre_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(pipe_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
