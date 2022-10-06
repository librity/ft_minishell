/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:22:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/06 17:00:18 by lpaulo-m         ###   ########.fr       */
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

MU_TEST(e_tst)
{
	_plist = NULL;

	add_exec(&_plist, (char *[]){"ls", NULL});
	execute_pipeline(_plist);

	// execve("/usr/bin/ls", (char *[]){"ls", NULL}, envht_to_envp());
}

MU_TEST(ls_multiple_arg_tst)
{
	_plist = NULL;
	add_exec(&_plist, (char *[]){"ls", "sources/", "tests/", NULL});
	execute_pipeline(_plist);

	_plist = NULL;
	add_exec(&_plist, (char *[]){"ls", "sources", "tests", NULL});
	execute_pipeline(_plist);
}

MU_TEST(ls_err_tst)
{
	_plist = NULL;

	add_exec(&_plist, (char *[]){"ls", "ls", NULL});
	execute_pipeline(_plist);
}

MU_TEST(ep_e_tst)
{
	_plist = NULL;

	add_exec(&_plist, (char *[]){"ls", "-a", NULL});
	add_pipe(&_plist);
	add_exec(&_plist, (char *[]){"grep", "main", NULL});

	execute_pipeline(_plist);
}

MU_TEST_SUITE(pipeline_suite)
{
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(e_tst);
	MU_RUN_TEST(ls_multiple_arg_tst);
	MU_RUN_TEST(ls_err_tst);

	MU_RUN_TEST(ep_e_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(pipeline_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
