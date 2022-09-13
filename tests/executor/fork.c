/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:22:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/13 15:10:17 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_parse_list	*_plist;

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

	execute_fork(_plist);
	dump_stdin();

	destroy_parse_list(&_plist);
}

MU_TEST(ep_e_tst)
{
	_plist = NULL;

	ft_dlst_add(&_plist, new_exec((char *[]){"ls", "-a", NULL}));
	ft_dlst_add(&_plist, new_pipe());
	ft_dlst_add(&_plist, new_exec((char *[]){"grep", "main", "main.c", NULL}));

	execute_fork(_plist);
	dump_stdin();

	execute_fork(_plist->next->next);
	dump_stdin();

	destroy_parse_list(&_plist);
}

MU_TEST(et_tst)
{
	_plist = NULL;

	add_truncate(&_plist, "tests/sandbox/et_tst");
	add_exec(&_plist, (char *[]){"ls", NULL});

	execute_fork(_plist);
	dump_stdin();

	destroy_parse_list(&_plist);
}

MU_TEST(ea_tst)
{
	_plist = NULL;

	add_append(&_plist, "tests/sandbox/ea_tst");
	add_exec(&_plist, (char *[]){"ls", NULL});

	execute_fork(_plist);
	dump_stdin();

	destroy_parse_list(&_plist);
}

MU_TEST(er_tst)
{
	_plist = NULL;

	add_read_file(&_plist, "tests/sandbox/er_tst");
	add_exec(&_plist, (char *[]){"grep", "a", NULL});

	execute_fork(_plist);
	dump_stdin();

	destroy_parse_list(&_plist);
}

MU_TEST(eh_tst)
{
	_plist = NULL;

	add_heredoc(&_plist, "exit");
	add_exec(&_plist, (char *[]){"grep", "a", NULL});

	write_to_stdin("a\nb\nc\nexit\nada\naaa");
	execute_fork(_plist);
	dump_stdin();

	destroy_parse_list(&_plist);
}

MU_TEST(e_relative_tst)
{
	_plist = NULL;

	add_exec(&_plist, (char *[]){"./tests/sandbox/ls", NULL});

	execute_fork(_plist);
	dump_stdin();

	destroy_parse_list(&_plist);
}

MU_TEST(e_absolute_tst)
{
	_plist = NULL;

	add_exec(&_plist, (char *[]){"/bin/ls", NULL});

	execute_fork(_plist);
	dump_stdin();

	destroy_parse_list(&_plist);
}

MU_TEST_SUITE(t_fork_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	// MU_RUN_TEST(e_tst);
	// MU_RUN_TEST(ep_e_tst);

	// MU_RUN_TEST(et_tst);
	// MU_RUN_TEST(ea_tst);

	// MU_RUN_TEST(er_tst);
	// MU_RUN_TEST(eh_tst);

	// MU_RUN_TEST(e_relative_tst);
	MU_RUN_TEST(e_absolute_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(t_fork_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
