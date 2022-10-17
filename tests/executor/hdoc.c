/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:22:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/17 15:31:00 by lpaulo-m         ###   ########.fr       */
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

	write_to_stdin_with_teardown("abc\na\nb\nc\nexit\nada\naaa", &cleanup_shell);
	spawn_single_pipe(_plist, _pids);
	waitpid(_pids[0], NULL, 0);
}

MU_TEST(hhre_tst)
{
	_plist = NULL;

	add_heredoc(&_plist, "1");
	add_heredoc(&_plist, "2");
	add_read_file(&_plist, "tests/sandbox/hhre_tst");
	add_exec(&_plist, (char *[]){"grep", "a", NULL});

	write_to_stdin_with_teardown("a\nb\nc\n1\nada\naaa\n2\nabc\ndfg\naba", &cleanup_shell);
	spawn_single_pipe(_plist, _pids);
	waitpid(_pids[0], NULL, 0);
}

MU_TEST_SUITE(pipe_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(he_tst);
	MU_RUN_TEST(hhre_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(pipe_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
